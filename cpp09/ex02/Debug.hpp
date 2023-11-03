#ifndef DEBUG_HPP_
#define DEBUG_HPP_

#include <vector>

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

typedef unsigned int uint;

class Debug {
	public:
		static void print_input(char** argv);
		static void print_vec(std::vector<uint>& vec);
		static void print_vec_insert(std::vector<uint>& dest, std::vector<uint>& src, uint insert_val);
		static void print_vec_bisearch(std::vector<uint>& vec, uint insert_val);
		static void vec_sorted(std::vector<uint>& vec);
	private:
		Debug();
		~Debug();
		Debug(const Debug & obj);
		Debug& operator=(const Debug& obj);
};

#endif  // DEBUG_HPP_
