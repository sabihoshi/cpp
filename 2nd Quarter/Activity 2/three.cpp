#include "prime.h"

int main()
{
start:
	int x;
	std::cout << "Enter x > ";
	std::cin >> x;
	std::cout << "Factors are: ";
	prime(x);
	std::cout << std::endl;
	goto start;
}