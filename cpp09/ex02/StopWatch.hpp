#ifndef STOPWATCH_HPP_
#define STOPWATCH_HPP_

#include <ctime>

class StopWatch {
	public:
		StopWatch();
		~StopWatch();
		StopWatch(const StopWatch & obj);
		StopWatch& operator=(const StopWatch& obj);
		double get_time_in_ms();
		void start();
		void stop();

	private:
		std::clock_t start_time;
		bool running;
};

#endif  // STOPWATCH_HPP_
