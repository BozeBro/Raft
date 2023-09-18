#include <timer.h>

#include <thread>
#include <chrono>
#include <atomic>
#include <memory>

namespace util {

Timer::Timer(double interval, std::function<void(void)> func)
: m_runData(std::make_shared<TimerRunning>(func, interval))
{}

void Timer::start() {
if (!m_runData->m_running) {
    m_runData->m_running = true;
    std::thread([safeThis = m_runData]() {
        double sleep_time = safeThis->m_interval;
        while (safeThis->m_running) {
            std::chrono::duration<double, std::milli> sleep(sleep_time);
            std::this_thread::sleep_for(sleep);
            auto current_time = std::chrono::high_resolution_clock::now();
            double elapsed_milli = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - safeThis->m_time.load()).count();
            if (safeThis->m_running && elapsed_milli >= safeThis->m_interval) {
                safeThis->m_func();
                sleep_time = safeThis->m_interval;
            } else {
                sleep_time = safeThis->m_interval - elapsed_milli;
            }
        }
    }).detach();
}
}


void Timer::resetTimer() {
    m_runData->m_time = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
    m_runData->m_running.store(false);
}

Timer::~Timer() {
    m_runData->m_running.store(false);
}

} //namespace util