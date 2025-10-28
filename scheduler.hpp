#include <functional>
#include <vector>

struct Task {
    std::function<void()> func;
    uint32_t period_ms;
    uint32_t lastRun_ms;
};

class Scheduler {
public:
    void addTask(std::function<void()> func, uint32_t period_ms);
    void tick();

private:
    std::vector<Task> tasks_;
    uint32_t currentTime_ms();
};
