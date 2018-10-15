// A program to demonstrate the use of stringstream
#include <iostream>
#include <conio.h>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <fstream>

#include "./headers/console.h"
using namespace std;

int main()
{
	std::string fileName = ".\\records\\user\\Kao\\Kao.txt";
	std::ifstream record(fileName.c_str());
	if (!record.is_open())
	{

		system("mkdir .\\records\\user\\Kao");
		std::ofstream record(fileName.c_str());
		if (record.is_open())
		{
			record << "1\n";
			record.close();
		}
	}
}