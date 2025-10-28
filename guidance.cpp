void Guidance::forceAbort() {
    stage_ = FlightStage::ABORT;
    cmd_.desiredThrust = 0;
    cmd_.desiredAttitude = Quaternion::identity();
}
