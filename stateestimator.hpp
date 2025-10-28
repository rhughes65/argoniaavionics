#include "Sensors.hpp"
#include "FlightState.hpp"

class StateEstimator {
public:
    void update(const Sensors& sensors);
    const FlightState& getState() const;

private:
    FlightState state_;
    EKF ekf_;   // Extended Kalman Filter or complementary filter
};
