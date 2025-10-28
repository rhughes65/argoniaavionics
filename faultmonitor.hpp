enum class FaultType {
    NONE            = 0,
    IMU_FAILURE     = 1 << 0,
    GPS_FAILURE     = 1 << 1,
    BARO_FAILURE    = 1 << 2,
    COMM_FAILURE    = 1 << 3,
    CRITICAL_SYSTEM = 1 << 4
};

class FaultMonitor {
public:
    void check(const Sensors& sensors, const FlightState& state);
    uint32_t getFlags() const { return flags_; }

private:
    uint32_t flags_ = 0;
    void handleSensorFailure(FaultType type);
    void triggerEmergencyAbort();
};

