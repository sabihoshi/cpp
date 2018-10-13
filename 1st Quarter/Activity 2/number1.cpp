#include <iostream>

using namespace std;

int main()
{
	char letter;
	cout << "Please input your letter > ";
	cin >> letter;

	if (letter == 'a' || letter == 'b' || letter == 'c')
		cout << "2";
	else if (letter == 'd' || letter == 'e' || letter == 'f')
		cout << "3";
	else if (letter == 'g' || letter == 'h' || letter == 'i')
		cout << "4";
	else if (letter == 'j' || letter == 'k' || letter == 'l')
		cout << "5";
	else if (letter == 'm' || letter == 'n' || letter == 'o')
		cout << "6";
	else if (letter == 'p' || letter == 'q' || letter == 'r' || letter == 's')
		cout << "7";
	else if (letter == 't' || letter == 'u' || letter == 'v')
		cout << "8";
	else if (letter == 'w' || letter == 'x' || letter == 'y')
		cout << "9";
	else
		cout << "You didn't enter a letter!";

	return 0;
}