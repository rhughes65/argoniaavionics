#include "HardwareIO.hpp"

void RecoverySystem::deployParachute() {
    // Ensure safe conditions
    if (!parachuteDeployed()) {
        HardwareIO::firePyro("PARACHUTE");
        Telemetry::sendAlert("Parachute deployed", 0);
    }
}

bool RecoverySystem::parachuteDeployed() {
    return HardwareIO::readPyroStatus("PARACHUTE");
}
