#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
start:
	string input;
	cout << "Enter your number > ";
	cin >> input;

	string original = input;
	reverse(input.begin(), input.end());

	if (input == original)
		cout << original << " is a Palindrome." << endl;
	else
		cout << original << " is not a Palindrome." << endl;
	goto start;
}
