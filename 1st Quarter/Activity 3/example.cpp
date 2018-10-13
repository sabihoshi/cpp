#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;
double x, y;
char d;
string z, s;
string l = ("wget.exe "), k = ("color ");

void multiplication()
{
	system("cls");
	cout << ("Multiplication") << endl;
	cin >> x;
	cin >> y;
	cout << ("The answer is:") << x * y << endl;
	Sleep(3000);
}

void division()
{
	cout << ("Division") << endl;
	cin >> x;
	cin >> y;
	cout << ("The answer is:") << x / y << endl;
	Sleep(3000);
}

void color()
{
	system("cls");
	cout << ("Console ColorChanger.") << endl;
	cout << ("choose a console color:") << endl;
	cout << ("0 = Black 8 = Gray") << endl;
	cout << ("1 = Blue 9 = Light Blue") << endl;
	cout << ("2 = Green A = Light Green") << endl;
	cout << ("3 = Aqua B = Light Aqua") << endl;
	cout << ("4 = Red C = Light Red") << endl;
	cout << ("5 = Purple D = Light Purple") << endl;
	cout << ("6 = Yellow E = Light Yellow") << endl;
	cout << ("7 = White F = Bright White") << "\n";
	cout << ("color: ");
	cin >> s;
	k = k + s;
	system(k.c_str());
}

int main()
{
	system("title OmniTool");
	system("cls");
	cout << ("Please choose a mode.") << endl;
	cout << ("Press m to goto Multiplication") << endl;
	cout << ("Press d to goto Division") << endl;
	cout << ("Press a to goto Addition") << endl;
	cout << ("Press s to goto Subtraction") << endl;
	cout << ("Type sqr to goto SquareRoot") << endl;
	cout << ("Press c to change color.") << endl;
	cout << ("Press w to goto Website Downloader.") << endl;
	cout << ("Press q to exit.") << endl;
	cout << ("Mode: ");
	cin >> d;

	switch (d)
	{
	case 'm':
		multiplication();
		break;
	case 'd':
		division();
		break;
	case 'c':
		color();
		break;
		// and so on
	}
}