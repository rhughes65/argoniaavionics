class FaultMonitor {
public:
    void check(const Sensors& sensors, const FlightState& state);
    uint32_t getFlags() const { return flags_; }

private:
    uint32_t flags_ = 0;
    void handleCriticalFault();
};
