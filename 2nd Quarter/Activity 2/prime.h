#ifndef _PRIME_
#define _PRIME_

#include <iostream>
#include <vector>
#include <math.h>

void push(int i);
void prime(int n)
{
	std::vector<int> arr(0);

	// Print the number of 2s that divide n
	while (n % 2 == 0)
	{
		arr.push_back(2);
		n = n / 2;
	}

	// n must be odd at this point.  So we can skip
	// one element (Note i = i + 2)
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		// While i divides n, print i and divide n
		while (n % i == 0)
		{
			arr.push_back(i);
			n = n / i;
		}
	}

	// This condition is to handle the case when n
	// is a prime number greater than 2
	if (n > 2)
		arr.push_back(n);

	// Output the array
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i];
		if (i != arr.size() - 1)
			std::cout << " x ";
	}
}
#endif
