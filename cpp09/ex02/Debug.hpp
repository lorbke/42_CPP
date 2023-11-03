#ifndef DEBUG_HPP_
#define DEBUG_HPP_

#include <vector>

#define GREEN "\033[32m"
#define MAGENTA "\033[45m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

typedef unsigned int uint;

template <typename Container>
class Debug {
	public:
		static void print_input(char** argv);
		static void print_vec(Container& vec);
		static void print_vec_insert(Container& dest, Container& src, uint insert_val);
		static void print_vec_bisearch(Container& vec, uint insert_val);
		static void vec_sorted(Container& vec);
	private:
		Debug();
		~Debug();
		Debug(const Debug<Container>& obj);
		Debug<Container>& operator=(const Debug<Container>& obj);
};

#endif  // DEBUG_HPP_
