#include <iostream>
using namespace std;

int main()
{
	string oper;
	int x, y;
	cout << "Please input x operator y > ";
	cin >> x >> oper >> y;

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
	else if (oper == "%" || oper == "\\" || oper == "mod" || oper == "modulo")
		cout << x % y;
	else
		cout << "Invalid operator! > " << oper;
	return 0;
}