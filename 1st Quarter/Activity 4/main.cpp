#include <iostream>
#include <string>

using namespace std;
string convert(int x)
{
	switch (x)
	{
	case 1:
		return "one";
		break;
	case 2:
		return "two";
		break;
	case 3:
		return "three";
		break;
	case 4:
		return "four";
		break;
	case 5:
		return "five";
		break;
	case 6:
		return "six";
		break;
	case 7:
		return "seven";
		break;
	case 8:
		return "eight";
		break;
	case 9:
		return "nine";
		break;
	default:
		return "";
		break;
	}
}

// Better.

string convertTens(int x)
{
	switch (x)
	{
	case 1:
		return "ten";
		break;
	case 2:
		return "twenty";
		break;
	case 3:
		return "thirty";
		break;
	case 4:
		return "forty";
		break;
	case 5:
		return "fifty";
		break;
	case 6:
		return "sixty";
		break;
	case 7:
		return "seventy";
		break;
	case 8:
		return "eighty";
		break;
	case 9:
		return "ninety";
		break;
	default:
		return "";
		break;
	}
}
string convertOnes(int x)
{
	switch (x)
	{
	case 1:
		return "eleven";
		break;
	case 2:
		return "twelve";
		break;
	case 3:
		return "thirteen";
		break;
	case 4:
		return "fourteen";
		break;
	case 5:
		return "fifteen";
		break;
	case 6:
		return "sixteen";
		break;
	case 7:
		return "seventeen";
		break;
	case 8:
		return "eighteen";
		break;
	case 9:
		return "nineteen";
		break;
	default:
		return "";
		break;
	}
}
void words()
{
	cout << "Please enter your number 0-9999 > ";
	int x;
	cin >> x;

	string output;
	if (x == 0)
	{
		output = "zero";
	}
	else if (x < 0)
	{
		output = "number cannot be below 0!";
	}
	else if (x > 9999)
	{
		output = "number cannot be above 9999!";
	}
	else
	{
		int thousands = x / 1000;
		x = x % 1000;
		int hundreds = x / 100;
		x = x % 100;
		int tens = x / 10;
		int ones = x % 10;
		if (thousands > 0)
		{
			output = convert(thousands) + " thousand";
		}
		if (hundreds > 0)
		{
			if (thousands > 0)
				output = output + " ";
			output = output + convert(hundreds) + " hundred";
		}
		if ((thousands > 0 || hundreds > 0) && (tens > 0 || ones > 0))
			output = output + " and ";
		if (tens == 1 && ones > 0)
		{
			output = output + convertOnes(ones);
		}
		else
		{
			output = output + convertTens(tens);
			if (tens > 1)
				output = output + " ";
			output = output + convert(ones);
		}
	}
	output.at(0) -= 32;
	cout << output << endl;
}
void roman()
{
	cout << "Please enter your number 1-3999 > " << endl;
	int y;
	cin >> y;

	if (y < 1)
	{
		cout << "Number cannot be below 1!" << endl;
	}
	else if (y > 3999)
	{
		cout << "Number cannot be above 3999!" << endl;
	}
	else
	{
		int m = y / 1000;
		y = y % 1000;
		int d = y / 500;
		y = y % 500;
		int c = y / 100;
		y = y % 100;
		int l = y / 50;
		y = y % 50;
		int x = y / 10;
		y = y % 10;
		int v = y / 5;
		int i = y % 5;

		string M = string(m, 'M');
		string D = string(d, 'D');
		string C = string(c, 'C');
		string L = string(l, 'L');
		string X = string(x, 'X');
		string V = string(v, 'V');
		string I = string(i, 'I');

		if (c == 4)
		{
			if (d == 1)
			{
				D = "CM";
				C = "";
			}
			else
				C = "CD";
		}
		if (x == 4)
		{
			if (l == 1)
			{
				L = "XC";
				X = "";
			}
			else
				X = "XL";
		}
		if (i == 4)
		{
			if (v == 1)
			{
				V = "IX";
				I = "";
			}
			else
				I = "IV";
		}
		cout << M + D + C + L + X + V + I << endl;
	}
}
void divisibility()
{
	cout << "Please enter your number 10-10000 > " << endl;
	int x;
	cin >> x;

	if (x < 10)
	{
		cout << "Number cannot be below 10!" << endl;
	}
	else if (x > 9999)
	{
		cout << "Number cannot be above 9999!" << endl;
	}
	else
	{
		int thousands = x / 1000;
		x = x % 1000;
		int hundreds = x / 100;
		x = x % 100;
		int tens = x / 10;
		int ones = x % 10;

		if (ones % 2 == 0)
		{
			cout << x << " is divisible by 2." << endl;
		}
		if ((ones + tens + hundreds + thousands) % 3 == 0)
		{
			cout << x << " is divisible by 3." << endl;
		}
		if (ones == 0 || ones == 5)
		{
			cout << x << " is divisible by 5." << endl;
		}
	}
}
int main()
{
choose:
	system("cls");
	cout << "[1] Numbers to Words" << endl
		 << "[2] Ordinal to Roman Numberals" << endl
		 << "[3] Divisibility Rules" << endl
		 << endl
		 << "Please enter what you want to use > ";
	int input;
	cin >> input;

	switch (input)
	{
	case 1:
		words();
		break;
	case 2:
		roman();
		break;
	case 3:
		divisibility();
		break;
	default:
		goto choose;
		break;
	}
	system("pause");
	goto choose;
	return 1;
}