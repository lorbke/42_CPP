#include "StopWatch.hpp"

// @todo implement correct canonical form
StopWatch::StopWatch() {}

StopWatch::~StopWatch() {}

StopWatch::StopWatch(const StopWatch & obj) { *this = obj; }

StopWatch& StopWatch::operator=(const StopWatch& obj) {
	(void)obj;
	return *this;
}
