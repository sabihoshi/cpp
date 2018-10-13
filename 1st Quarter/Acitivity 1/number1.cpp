#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double miles;

	cout << "Enter your mileage\n";
	cin >> miles;

	cout << fixed;
	cout << setprecision(2);

	double feet = miles * 5280;
	double inches = feet * 12;
	double centimeters = inches * 2.54;
	double kilometers = centimeters / 100000;
	cout << kilometers << endl;
	return 0;
}

