#include <iostream>
int main()
{
	int x, y = 0;
	std::cout << "Enter x > ";
	std::cin >> x;
	for (int i = 1; i <= x; i++)
		y += i * i;
	std::cout << y;
	return 0;
}