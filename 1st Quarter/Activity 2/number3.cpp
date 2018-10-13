#include <iostream>

using namespace std;

int main()
{
	int x, y;
	cout << "Please input x y > ";
	cin >> x >> y;
	cout << "Points are located in ";
	if (x == 0)
	{
		if (y == 0)
			cout << "the Origin";
		else
			cout << "x axis";
	}
	else if (y == 0)
		cout << "y axis";
	else if (x > 0)
	{
		if (y > 0)
			cout << "Quadrant I";
		else
			cout << "Quadrant II";
	}
	else
	{
		if (y > 0)
			cout << "Quadrant IV";
		else
			cout << "Quadrant III";
	}
	return 0;
}