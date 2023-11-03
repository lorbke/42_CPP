#include "StopWatch.hpp"
#include <ctime>

#define CLOCKS_PER_MSEC (CLOCKS_PER_SEC / 1000)

StopWatch::StopWatch() : start_time(0), running(false) {}

StopWatch::~StopWatch() {}

StopWatch::StopWatch(const StopWatch & obj) {
	*this = obj;
	running = obj.get_running();
	start_time = obj.get_start_time();
}

StopWatch& StopWatch::operator=(const StopWatch& obj) {
	running = obj.get_running();
	start_time = obj.get_start_time();
	return *this;
}

void StopWatch::start() {
	start_time = std::clock();
	running = true;
}

void StopWatch::stop() {
	running = false;
}

bool StopWatch::get_running() const {
	return running;
}

std::clock_t StopWatch::get_start_time() const {
	return start_time;
}

double StopWatch::get_time_in_ms() {
	if (running) {
		return (double)(std::clock() - start_time) / CLOCKS_PER_MSEC;
	} else {
		return (double)start_time / CLOCKS_PER_MSEC;
	}
}