#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int hours;

	cout << "Enter how many hours\n";
	cin >> hours;

	int days = hours / 24;
	int weeks = days / 7;
	days = days % 7;
	hours = hours % 24;

	cout << "Weeks: " << weeks << endl;
	cout << "Days: " << days << endl;
	cout << "Hours: " << hours;

	return 0;
}