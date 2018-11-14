#ifndef GRAPH_H
#define GRAPH_H

#include <iostream> // various
#include <fstream>  // files
#include <vector>   // arrays
#include <string>   // stoi

#ifndef TABLE_H
#include "./table.h"
#endif // !TABLE_H

#ifndef COLOR_H
#include "./color.h"
#endif // !COLOR_H

using namespace access;
using namespace colors;

std::vector<std::string> readLines(std::string fileName)
{
	std::vector<std::string> returnValueVector;
	std::string currentLineBuffer;

	std::ifstream inputStream(fileName);
	if (!inputStream.good())
		return returnValueVector;

	while (std::getline(inputStream, currentLineBuffer))
	{
		returnValueVector.push_back(currentLineBuffer);
	}

	inputStream.close();
	return returnValueVector;
}
void graph()
{
	std::string fileDir = ".\\records\\user\\" + username + "\\";
	int choice;
	std::vector<std::string> files = readLines(fileDir + username + ".txt");
	for (unsigned int i = 0; i < files.size(); i++)
	{
		std::cout << "[" << i << "] " << files.at(i) << std::endl;
	}
	std::cout << "What record do you want to open? > ";
	std::cin >> choice;
	std::vector<std::string> data = readLines(fileDir + files.at(choice) + "_data.txt");
	int minWork = std::stoi(data.at(0));
	int hourlyRate = std::stoi(data.at(1));
	int calDays = std::stoi(data.at(2));
	int calStart = std::stoi(data.at(3));
	int weekDay = calStart;
	int week = 0;
	int hourInt, pay;
	std::vector<std::string> hours = readLines(fileDir + files.at(choice) + "_hours.txt");
	calendar(7, 11, calStart, calDays);
	for (int i = 1; i <= calDays; i++)
	{
		hourInt = std::stoi(hours.at(i));
		if (weekDay == 0)
		{
			if (hourInt > 0)
				color(2);
			else
				color(fgColor);
			pay = hourInt * (hourlyRate * minWork);
		}
		else if (hourInt > minWork)
		{
			color(2);
			pay = ((hourInt - minWork) * (hourlyRate * 2)) + (hourInt * hourlyRate);
		}
		else if (hourInt < minWork)
		{
			color(4);
			pay = hourInt * hourlyRate;
		}
		else
		{	color(fgColor);
			pay = 0;
		}
		gotoxy(9 + (12 * weekDay), 4 + (4 * week));
		std::cout << std::setw(2) << hours.at(i);
		gotoxy(2 + (12 * weekDay), 5 + (4 * week));
		std::cout << std::setw(9) << pay;
		if (weekDay == 6)
		{
			week++;
			weekDay = 0;
		}
		else
			weekDay++;
	}
}

#endif // !GRAPH_H
