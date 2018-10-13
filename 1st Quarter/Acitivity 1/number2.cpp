#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double centimeters;

	cout << "Enter your value\n";
	cin >> centimeters;

	cout << fixed;
	cout << setprecision(2);

	double inches = centimeters / 2.54;
	double feet = inches / 12;

	cout << "Inches: " << inches << "\"" << endl;
	return 0;
}