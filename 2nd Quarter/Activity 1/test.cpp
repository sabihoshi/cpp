#include <iostream>
#include <string>

int main()
{
	for (int i = 0; i < 7; i++)
	{
		int space = 7 - i;
		std::cout << std::string(space + 18, ' ') << std::string((i * 2) + 1, '*') << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		int space = (i * 3);
		std::cout << std::string(space, ' ') << std::string(((25 - (i * 3)) * 2) + 1, '*') << std::endl;
	}
	for (int i = 0; i < 3; i++)
	{
		int space = 3 - i;
		std::cout << std::string(space + 10, ' ') << std::string((i * 2) + 25, '*') << std::endl;
	}
	for (int i = 0; i < 7; i++)
	{
		int space = 7 - i;
		std::cout << std::string(space + 3, ' ') << std::string(((6 - i) * 2) + 1, '*') << std::string(((i * 3) * 2) + 5, ' ') << std::string(((6 - i) * 2) + 1, '*') << std::endl;
	}
	return 0;
}