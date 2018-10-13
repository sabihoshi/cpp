#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> x = {5, 3, 2, 1};
	cout << x.size() << endl;
	for (int i = 0; i < x.size(); i++)
	{
		cout << x[i];
	}
}