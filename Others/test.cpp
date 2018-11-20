#include <iostream>
#include <vector>

int main()
{
	std::vector<char> choices = {'e', 'd', 'b', 'd', 'e', 'e', 'a', 'e', 'b', 'd', 'b', 'd', 'a', 'e', 'd', 'b', 'd', 'b', 'd', 'd', 'b', 'a', 'c', 'b', 'd', 'e', 'a', 'e', 'd', 'e'};
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (int i = 0; i < choices.size(); i++)
	{
		switch (choices[i])
		{
		case 'a':
			a++;
			break;
		case 'b':
			b++;
			break;
		case 'c':
			c++;
			break;
		case 'd':
			d++;
			break;
		case 'e':
			e++;
			break;
		}
	}
	std::cout << "Words of Affirmation		A: " << a << std::endl
			  << "Quality Time			B: " << b << std::endl
			  << "Receiving Gifts			C: " << c << std::endl
			  << "Acts of Service			D: " << d << std::endl
			  << "Physical Touch			E: " << e << std::endl;
}