void Control::shutdownAll() {
    tvcPID_.reset();
    attitudePID_.reset();
    throttlePID_.reset();
    Actuators::cutEngines();
    Actuators::lockServos();
}
