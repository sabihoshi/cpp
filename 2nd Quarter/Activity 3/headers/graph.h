#ifndef GRAPH_H
#define GRAPH_H

#include <iostream> // various
#include <fstream>  // files
#include <vector>   // arrays
#include <string>   // stoi
#include <iomanip>  // setprecision

#ifndef TABLE_H
#include "./table.h"
#endif // !TABLE_H

#ifndef COLOR_H
#include "./color.h"
#endif // !COLOR_H

#ifndef CONSOLE_H
#include "./console.h"
#endif // !CONSOLE_H

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
userStart:
	gotoxy(0, 6);
	eos();
	std::string usernameView = username;
	std::string userOut;
	for (unsigned int i = 0; i < usernameView.size(); i++)
		userOut += toupper(usernameView[i]);
	std::cout << "\033[4mUsername\033[24m: " << userOut;
	char ch;
	ch = _getch();
usernameAsk:
	while (ch != 13) // 13 is enter
	{
		switch (ch)
		{
		case 8: // 8 is backspace
		case 127:
			if (usernameView.size() != 0)
			{
				userOut.resize(userOut.size() - 1);
				usernameView.resize(usernameView.size() - 1);
				std::cout << "\b \b";
			}
			break;
		case 27: // 27 is escape
			usernameView.resize(0);
			gotoxy(10, 6);
			std::cout << "\033[K";
			break;
		case 32: // 32 is space
			break;
		default:
			if (usernameView.size() != 16)
			{
				userOut += (char)toupper(ch);
				std::cout << (char)toupper(ch);
				usernameView += ch;
			}
		}
		ch = _getch();
		goto usernameAsk;
	}
	rtrim(usernameView);
	std::cout << "\033[0G";
	std::cout << "Username: " << userOut << std::endl;
	std::string fileDir = ".\\records\\user\\" + usernameView + "\\";
	std::ifstream inputStream(fileDir + usernameView + ".txt");
	if (!inputStream.good())
	{
		std::cout << "User does not have any records!" << std::endl;
		_getch();
		goto userStart;
	}
	inputStream.close();
	int choice;
	std::vector<std::string> files = readLines(fileDir + usernameView + ".txt");
	consoleOffset(0, files.size(), true);
	for (unsigned int i = 0; i < files.size(); i++)
	{
		std::cout << "[" << i << "] " << files.at(i) << std::endl;
	}
	consoleOffset(0, 1, true);
	std::cout << "What record to open? > ";
	std::cin >> choice;
	std::vector<std::string> data = readLines(fileDir + files.at(choice) + "_data.txt");
	int minWork = std::stoi(data.at(0));
	int hourlyRate = std::stoi(data.at(1));
	int calDays = std::stoi(data.at(2));
	int calStart = std::stoi(data.at(3));
	int weekDay = calStart;
	int week = 0;
	int hourInt, pay;
	int payTotal = 0;
	consoleSize(85, 28, true);
	std::vector<std::string> hours = readLines(fileDir + files.at(choice) + "_hours.txt");
	calendar(7, 11, calStart, calDays);

	enableThousands();
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
		{
			color(fgColor);
			pay = 0;
		}
		payTotal += pay;
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
	payComputation(payTotal);
}
#endif // !GRAPH_H
