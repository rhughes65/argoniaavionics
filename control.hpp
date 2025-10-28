#include "FlightState.hpp"
#include "Guidance.hpp"

class PID {
public:
    PID(float kp, float ki, float kd);
    float compute(float error, float dt);
private:
    float kp_, ki_, kd_;
    float integral_, prevError_;
};

class Control {
public:
    void update(const FlightState& state, const GuidanceCommand& cmd);

private:
    PID attitudePID_{1.0f, 0.1f, 0.05f};
    PID tvcPID_{0.8f, 0.05f, 0.03f};
    PID throttlePID_{1.0f, 0.2f, 0.1f};
};
