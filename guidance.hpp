#include "FlightState.hpp"

enum class FlightStage {
    PRELAUNCH, ASCENT_STAGE1, COAST, SEPARATION, ASCENT_STAGE2, PAYLOAD, ABORT, LANDED
};

struct GuidanceCommand {
    Quaternion desiredAttitude;
    float desiredThrust;
};

class Guidance {
public:
    void update(const FlightState& state);
    const GuidanceCommand& getCommand() const;

private:
    void handlePrelaunch(const FlightState& s);
    void handleStage1(const FlightState& s);
    void handleCoast(const FlightState& s);
    void handleStage2(const FlightState& s);

    GuidanceCommand cmd_;
    FlightStage stage_ = FlightStage::PRELAUNCH;
};
