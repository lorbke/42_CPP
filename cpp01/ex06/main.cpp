
#include "Harl.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

enum	Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./complain [DEBUG|INFO|WARNING|ERROR]" << std::endl;
		return (EXIT_FAILURE);
	}

	Harl 	harl;
	harl.complain(argv[1]);

	return (EXIT_SUCCESS);
}
