#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;
int main()
{
	vector<string> users;
	string username = "glaizel";
	string password = "123456";
	ifstream inFile("./users.txt");
	string currentLine;
	while (getline(inFile, currentLine))
	{
		users.push_back(currentLine);
	}
	for (int i = 0; i < users.size() / 2; i++)
	{
		if (username == users[i * 2] && password[(i * 2) + 1])
		goto congrats;
	}
	cout << "Failed";
	return 0;
congrats:
	cout << "Yay";
	return 0;
}