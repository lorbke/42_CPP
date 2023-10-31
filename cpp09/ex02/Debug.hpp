#ifndef DEBUG_HPP_
#define DEBUG_HPP_

#include <vector>

typedef unsigned int uint;

class Debug {
	public:
		static void debug_print_input(char** argv);
		static void debug_print_vec(std::vector<uint>& vec);
	private:
		Debug();
		~Debug();
		Debug(const Debug & obj);
		Debug& operator=(const Debug& obj);
};

#endif  // DEBUG_HPP_
