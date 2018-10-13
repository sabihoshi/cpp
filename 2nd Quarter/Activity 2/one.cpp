#include <iostream>

int sum(int x, int y)
{
	return x + y;
}

int main()
{
	int x, y;
	std::cout << "Enter x & y > ";
	std::cin >> x >> y;

	std::cout << std::endl << "Answer is " << sum(x, y);
}