void Telemetry::sendAlert(const std::string& message, int code) {
    TelemetryPacket pkt;
    pkt.timestamp = getTimestamp();
    pkt.message = message;
    pkt.code = code;
    pkt.priority = HIGH_PRIORITY;
    transmit(pkt);
}
