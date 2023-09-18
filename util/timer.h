#include <functional>
#include <atomic>
#include <chrono>
#include <thread>
#include <memory>

namespace util
{
class TimerRunning;

class Timer {
public:
    // func needs to be thread safe
    Timer(double interval, std::function<void(void)> func);
    void start();
    void stop();
    void resetTimer();
    ~Timer();

private:
    const std::shared_ptr<TimerRunning> m_runData;
};

struct TimerRunning {
    TimerRunning(std::function<void(void)> func, double interval)
    : m_func(func)
    , m_interval(interval)
    , m_running(false)
    , m_time{std::chrono::high_resolution_clock::now()}
    {}
std::function<void(void)> m_func;
const double m_interval;
std::atomic<bool> m_running;
std::atomic<std::chrono::steady_clock::time_point> m_time;
};


} // namespace util

