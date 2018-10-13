#include <iostream>
void star(int x)
{
	for (int y = 0; y < x; y++)
		std::cout << '*';
}
void space(int x)
{
	for (int y = 0; y < x; y++)
		std::cout << ' ';
}
int main()
{
	for (int i = 0; i < 7; i++)
	{
		space((7 - i) + 18);
		star((i * 2) + 1);
		std::cout << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		space(i * 3);
		star(((25 - (i * 3)) * 2) + 1);
		std::cout << std::endl;
	}
	for (int i = 0; i < 3; i++)
	{
		space((3 - i) + 10);
		star((i * 2) + 25);
		std::cout << std::endl;
	}
	for (int i = 0; i < 7; i++)
	{
		space((7 - i) + 3);
		star(((6 - i) * 2) + 1);
		space(((i * 3) * 2) + 5);
		star(((6 - i) * 2) + 1);
		std::cout << std::endl;
	}
	return 0;
}