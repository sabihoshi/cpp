#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int seconds;

	cout << "Enter how many seconds\n";
	cin >> seconds;

	int minutes = seconds / 60;
	int hours = minutes / 60;
	seconds = seconds % 60;
	minutes = minutes % 60;

	cout << hours << " hours, ";
	cout << minutes << " minutes, ";
	cout << seconds << " seconds." << endl;

	return 0;
}