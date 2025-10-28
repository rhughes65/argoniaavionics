void FaultMonitor::check(const Sensors& sensors, const FlightState& state) {
    // --- Sensor Health Checks ---
    if (!sensors.imuHealthy()) {
        flags_ |= static_cast<uint32_t>(FaultType::IMU_FAILURE);
        handleSensorFailure(FaultType::IMU_FAILURE);
    }

    if (!sensors.gpsHealthy()) {
        flags_ |= static_cast<uint32_t>(FaultType::GPS_FAILURE);
        handleSensorFailure(FaultType::GPS_FAILURE);
    }

    if (!sensors.baroHealthy()) {
        flags_ |= static_cast<uint32_t>(FaultType::BARO_FAILURE);
        handleSensorFailure(FaultType::BARO_FAILURE);
    }

    // Add more health checks as needed
}
void FaultMonitor::handleSensorFailure(FaultType type) {
    // Log the issue
    Telemetry::sendAlert("Sensor failure detected", static_cast<int>(type));

    // Try to recover or use fallback
    bool recovered = Sensors::attemptRecovery(type);

    if (!recovered) {
        // Unrecoverable -> initiate emergency sequence
        triggerEmergencyAbort();
    }
}
void FaultMonitor::triggerEmergencyAbort() {
    Telemetry::sendAlert("Emergency abort triggered", 0);

    // Cut all engine outputs immediately
    Actuators::cutEngines();
    Actuators::lockServos();

    // Deploy recovery system
    RecoverySystem::deployParachute();

    // Notify other modules
    Guidance::forceAbort();
    Control::shutdownAll();
    
    // Set stage to ABORT
    FlightStateManager::setStage(FlightStage::ABORT);

    // Mark fault flag
    flags_ |= static_cast<uint32_t>(FaultType::CRITICAL_SYSTEM);
}
