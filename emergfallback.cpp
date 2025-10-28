bool Sensors::attemptRecovery(FaultType type) {
    switch (type) {
        case FaultType::IMU_FAILURE:
            return imu_.resetAndRecalibrate();
        case FaultType::GPS_FAILURE:
            return gps_.restartReceiver();
        default:
            return false; // unrecoverable
    }
}
