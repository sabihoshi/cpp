// A program to demonstrate the use of stringstream
#include <iostream>
#include <conio.h>
#include <sstream>
using namespace std;

int main()
{
start:
	int x = getch();
	char ch = x;
	// Now the variable x holds the value 12345
	cout << "Value of x : " << x << ", " << ch << ", " << ch.c_str();
	goto start;
	return 0;
}