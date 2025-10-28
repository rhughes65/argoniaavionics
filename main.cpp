#include "Scheduler.hpp"
#include "Sensors.hpp"
#include "StateEstimator.hpp"
#include "Guidance.hpp"
#include "Control.hpp"
#include "Telemetry.hpp"
#include "FaultMonitor.hpp"

int main() {
    // --- Initialization ---
    Hardware::initPower();
    Hardware::initPyro();
    Hardware::initServos();
    Hardware::initWatchdog();

    Sensors sensors;
    StateEstimator estimator;
    Guidance guidance;
    Control control;
    Telemetry telemetry;
    FaultMonitor faultMonitor;

    Scheduler scheduler;

    // --- Register periodic tasks ---
    scheduler.addTask([&]{ sensors.update(); }, 5_ms);
    scheduler.addTask([&]{ estimator.update(sensors); }, 5_ms);
    scheduler.addTask([&]{ guidance.update(estimator.getState()); }, 20_ms);
    scheduler.addTask([&]{ control.update(estimator.getState(), guidance.getCommand()); }, 5_ms);
    scheduler.addTask([&]{ telemetry.send(estimator.getState(), sensors, faultMonitor.getFlags()); }, 200_ms);
    scheduler.addTask([&]{ faultMonitor.check(sensors, estimator.getState()); }, 100_ms);

    // --- Enter main loop ---
    while (true) {
        scheduler.tick();        // runs due tasks
        Hardware::feedWatchdog();
    }

    return 0;
}
