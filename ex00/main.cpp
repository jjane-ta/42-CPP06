#include "ScalarConverter.hpp"
#include <cerrno>
#include <cstring>


int main(int argc, char **argv)
{
	if (argc != 2) std::cout << std::string(std::strerror(EINVAL)) << std::endl;
	else ScalarConverter::convert(argv[1]);
}