#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double pounds;

	cout << "Enter your weight in pounds\n";
	cin >> pounds;

	cout << fixed;
	cout << setprecision(2);

	double grams = pounds * 454;

	cout << "Weight: " << grams << "g" << endl;
	return 0;
}