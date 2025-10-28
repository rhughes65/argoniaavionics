void Guidance::update(const FlightState& s) {
    switch (stage_) {
        case FlightStage::PRELAUNCH:
            if (GroundCommand::launchReceived()) stage_ = FlightStage::ASCENT_STAGE1;
            cmd_.desiredThrust = 0;
            break;

        case FlightStage::ASCENT_STAGE1:
            cmd_.desiredThrust = computeThrustProfile(s.altitude);
            cmd_.desiredAttitude = computePitchProfile(s.time);
            if (s.altitude > cutoffAltitude_) stage_ = FlightStage::SEPARATION;
            break;

        case FlightStage::SEPARATION:
            if (performSeparation()) stage_ = FlightStage::ASCENT_STAGE2;
            break;

        case FlightStage::ASCENT_STAGE2:
            cmd_.desiredThrust = computeStage2Thrust(s.altitude);
            break;

        default:
            cmd_.desiredThrust = 0;
    }
}
