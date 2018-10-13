#include <iostream>	

void multiply()
{
	int x, y, a = 0;
	std::cout << "Enter x and y > ";
	std::cin >> x >> y;

	for (int i = 0; i < y; i++)
	{
		a += x;
	}
	std::cout << "Result: " << a << std::endl;
}
void fibonacci()
{
	int l, o, x = 1, y = NULL;
	std::string a;
	std::cout << "Enter length > ";
	std::cin >> l;

	std::cout << "Result: ";
	for (int i = 2; i < l; i++)
	{
		std::cout << x << ", ";
		o = x + y;
		y = x;
		x = o;
	}
	o = x + y;
	y = x;
	x = o;
	std::cout << y << ", " << x << std::endl;
}
void sum()
{
	int x, y = 0;
	std::cout << "Enter x > ";
	std::cin >> x;

	for (int i = 1; i < x; i++)
	{
		std::cout << i;
		y += i;
		std::cout << " + ";
	}
	y += x;
	std::cout << x << " = " << y;
	std::cout << std::endl;
}
int main()
{
choose:
	system("cls");
	std::cout << "[1] Multiplication" << std::endl
			  << "[2] Fibonacci" << std::endl
			  << "[3] Sum series" << std::endl
			  << std::endl
			  << "Please enter what you want to use > ";
	int input;
	std::cin >> input;

	switch (input)
	{
	case 1:
		multiply();
		break;
	case 2:
		fibonacci();
		break;
	case 3:
		sum();
		break;
	default:
		goto choose;
		break;
	}
	system("pause");
	goto choose;
	return 1;
}