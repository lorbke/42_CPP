#include "StopWatch.hpp"

// @todo implement correct canonical form
StopWatch::StopWatch() : start_time(0), running(false) {}

StopWatch::~StopWatch() {}

StopWatch::StopWatch(const StopWatch & obj) { *this = obj; }

StopWatch& StopWatch::operator=(const StopWatch& obj) {
	(void)obj;
	return *this;
}

void StopWatch::start() {
	start_time = std::clock();
	running = true;
}

void StopWatch::stop() {
	running = false;
}

double StopWatch::getTime() {
	if (running) {
		return (double)(std::clock() - start_time) / CLOCKS_PER_SEC;
	} else {
		return (double)start_time / CLOCKS_PER_SEC;
	}
}