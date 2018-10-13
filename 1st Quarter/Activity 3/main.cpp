#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
double x, y;

void miles()
{
	cout << "Enter your mileage\n";
	cin >> x;

	cout << fixed;
	cout << setprecision(2);

	double feet = x * 5280;
	double inches = feet * 12;
	double centimeters = inches * 2.54;
	double kilometers = centimeters / 100000;
	cout << "Answer: " << kilometers << endl;
}
void centimeters()
{
	cout << "Enter your value\n";
	cin >> x;

	cout << fixed;
	cout << setprecision(2);

	double inches = x / 2.54;
	double feet = inches / 12;

	cout << "Feet: " << feet << "\'" << endl;
	cout << "Inches: " << inches << "\"" << endl;
}
void pounds()
{
	cout << "Enter your weight in pounds\n";
	cin >> x;

	cout << fixed;
	cout << setprecision(2);

	double grams = x * 454;

	cout << "Weight: " << grams << "g" << endl;
}
void wdh()
{
	int x;
	cout << "Enter how many hours\n";
	cin >> x;

	int days = x / 24;
	int weeks = days / 7;
	days = days % 7;
	x = x % 24;

	cout << "Weeks: " << weeks << endl;
	cout << "Days: " << days << endl;
	cout << "Hours: " << x << endl;
}
void hms()
{
	int x;
	cout << "Enter how many seconds\n";
	cin >> x;

	int minutes = x / 60;
	int hours = minutes / 60;
	x = x % 60;
	minutes = minutes % 60;

	cout << hours << " hours, ";
	cout << minutes << " minutes, ";
	cout << x << " seconds." << endl;
}
void telekeypad()
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
}
void calculate()
{
	string oper;
	cout << "Please input x operator y > ";
	cin >> x >> oper >> y;

	if (oper == "+" || oper == "plus")
		cout << x + y;
	else if (oper == "-" || oper == "minus" || oper == "abc")
		cout << x - y;
	else if (oper == "/" || oper == "divide")
	{
		if (y == 0)
			cout << "y must not be 0!";
		else
			cout << x / y;
	}
	else if (oper == "*" || oper == "multiply")
		cout << x * y;
	else
		cout << "Invalid operator! > " << oper;
}
void points()
{
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
}
int main()
{
choose:
	system("cls");
	int activity;
	cout << "[1] Activity 1" << endl;
	cout << "[2] Activity 2" << endl;
	cout << "[3] Change color" << endl;
	cout << "[4] Exit" << endl;
	cout << "\nChoose an Activity > ";
	cin >> activity;
	switch (activity)
	{
	case 1:
	{
	activity1:
		system("cls");
		int input;
		cout << "[1] Miles to Kilometers" << endl;
		cout << "[2] Centimeters to Inches" << endl;
		cout << "[3] Pounds to Grams" << endl;
		cout << "[4] Hours to Weeks, Days, Hours" << endl;
		cout << "[5] Seconds to Hours, Minutes, Seconds" << endl;
		cout << "[6] Go back" << endl;
		cout << "\nChoose an Activity > ";
		cin >> input;

		switch (input)
		{
		case 1:
			miles();
			break;
		case 2:
			centimeters();
			break;
		case 3:
			pounds();
			break;
		case 4:
			wdh();
			break;
		case 5:
			hms();
			break;
		case 6:
			goto choose;
			break;
		}
		cout << endl;
		system("pause");
		goto activity1;
		break;
	}
	case 2:
	{
	activity2:
		system("cls");
		int input;
		cout << "[1] Telekeypad" << endl;
		cout << "[2] Calculator" << endl;
		cout << "[3] Cartesian plane" << endl;
		cout << "[4] Calculator but better (decimal)" << endl;
		cout << "[5] Go back" << endl;
		cout << "\nChoose an Activity > ";
		cin >> input;

		switch (input)
		{
		case 1:
			telekeypad();
			break;
		case 2:
			calculate();
			break;
		case 3:
			points();
			break;
		case 4:
			cout << fixed;
			cout << setprecision(2);
			calculate();
			break;
		case 5:
			goto choose;
			break;
		}
		cout << endl;
		system("pause");
		system("cls");
		goto activity2;
		break;
	}
	case 3:
	color:
		system("cls");
		char color;
		cout << "0 = Black       8 = Gray" << endl;
		cout << "1 = Blue        9 = Light Blue" << endl;
		cout << "2 = Green       A = Light Green" << endl;
		cout << "3 = Aqua        B = Light Aqua" << endl;
		cout << "4 = Red         C = Light Red" << endl;
		cout << "5 = Purple      D = Light Purple" << endl;
		cout << "6 = Yellow      E = Light Yellow" << endl;
		cout << "7 = White       F = Bright White" << endl;
		cout << "! = Go back" << endl;
		cout << "\n Choose a color > ";
		cin >> color;
		switch (color)
		{
		case '0':
			system("color 0");
			break;
		case '1':
			system("color 1");
			break;
		case '2':
			system("color 2");
			break;
		case '3':
			system("color 3");
			break;
		case '4':
			system("color 4");
			break;
		case '5':
			system("color 5");
			break;
		case '6':
			system("color 6");
			break;
		case '7':
			system("color 7");
			break;
		case '8':
			system("color 8");
			break;
		case '9':
			system("color 9");
			break;
		case 'a':
			system("color a");
			break;
		case 'b':
			system("color b");
			break;
		case 'c':
			system("color c");
			break;
		case 'd':
			system("color d");
			break;
		case 'e':
			system("color e");
			break;
		case 'f':
			system("color f");
			break;
		case '!':
			goto choose;
			break;
		default:
			cout << "Invalid color!" << endl;
			system("pause");
			goto color;
			break;
		}
		goto color;
		break;
	case 4:
		return 0;
		break;
	default:
	{
		cout << "You entered an incorrect number!" << endl;
		system("pause");
		goto choose;
		break;
	}
	}
}