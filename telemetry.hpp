#include "FlightState.hpp"
#include "Sensors.hpp"

class Telemetry {
public:
    void send(const FlightState& state, const Sensors& sensors, uint32_t faultFlags);

private:
    void transmit(const TelemetryPacket& pkt);
    void logToFlash(const TelemetryPacket& pkt);
};
