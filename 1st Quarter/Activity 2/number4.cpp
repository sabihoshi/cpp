#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	string oper;
	float x, y;
	cout << "Please input x operator y > ";
	cin >> x >> oper >> y;

	cout << fixed;
	cout << setprecision(2);

	if (oper == "+" || oper == "plus")
		cout << x + y;
	else if (oper == "-" || oper == "minus" || oper == "abc")
		cout << x - y;
	else if (oper == "/" || oper == "divide")
	{
		if (y == 0)
			cout << "yx must not be 0!";
		else
			cout << x / y;
	}
	else if (oper == "*" || oper == "multiply")
		cout << x * y;
	else
		cout << "Invalid operator! > " << oper;
	return 0;
}