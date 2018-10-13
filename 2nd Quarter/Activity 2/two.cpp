#include <iostream>

int max(int x, int y, int z)
{
	if (x > y)
	{
		if (x > z)
			return x;
		else
			return z;
	}
	else
	{
		if (y > z)
			return y;
		else
			return z;
	}
}

int min(int x, int y, int z)
{
	if (x < y)
	{
		if (x < z)
			return x;
		else
			return z;
	}
	else
	{
		if (y < z)
			return y;
		else
			return z;
	}
}

int main()
{
	int x, y, z;
	std::cout << "Enter x y z > ";
	std::cin >> x >> y >> z;
	std::cout << std::endl
			  << "Highest is: " << max(x, y, z)
			  << std::endl
			  << "Lowest is: " << min(x, y, z);
}