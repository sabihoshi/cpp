#ifndef RECORD_H
#define RECORD_H

#include <iostream> // various
#include <conio.h>  // _getch
#include <iomanip>  // setw
#include <fstream>  // files
#include <string>   // strings
#include <sstream>  // sstreams

#ifndef TABLE_H
#include "./table.h"
#endif // !TABLE_H

#ifndef COLOR_H
#include "./color.h"
#endif // !COLOR_H

#ifndef CONSOLE_H
#include "./console.h"
#endif // !CONSOLE_H

using namespace colors;
using namespace access;

void record()
{
	int minWork, hourlyRate, pay, calStart, calDays, hourInt;
	std::string calName;
workHours:
	std::cout << "Hours needed per day: ";
	std::cin >> minWork;
	if (minWork > 24 || minWork < 0)
	{
		std::cout << "Invalid hours!" << std::endl;
		goto workHours;
	}
	std::cout << "Enter your hourly rate: ";
	std::cin >> hourlyRate;
	std::cout
		<< "0 - Sunday" << std::endl
		<< "1 - Monday" << std::endl
		<< "2 - Tuesday" << std::endl
		<< "3 - Wednesday" << std::endl
		<< "4 - Thursday" << std::endl
		<< "5 - Friday" << std::endl
		<< "6 - Saturday" << std::endl
		<< std::endl
		<< "Enter which day should the calendar start: ";
	std::cin >> calStart;
	std::cout << "Enter how many days the calendar should have: ";
	std::cin >> calDays;
	std::cout << "Enter the name of your record: ";
	std::cin >> calName;
	consoleSize(85, 28, true);
	calendar(7, 11, calStart, calDays);
	int weekDay = calStart;
	int week = 0;
	int day = 1;
	char ch;
	std::vector<std::string> hours(calDays + 1);
	std::vector<int> payTable(calDays);
	enableThousands();
recordHours:
	gotoxy(8 + (12 * weekDay), 4 + (4 * week));
	color(fgColor);
	std::stringstream hourStream(hours.at(day));
	hourStream >> hourInt;
	if (hourInt < minWork)
		color(4);
	else if (hourInt > minWork)
		color(2);
	else
		color(fgColor);
	std::cout << std::setw(3) << '>' + hours.at(day);
	ch = _getch();
	while (ch != 13) // 13 is enter
	{
		switch (ch)
		{
		case 8: // 8 is backspace
		case 127:
			if (hours.at(day).size() != 0)
			{
				hours.at(day).resize(hours.at(day).size() - 1);
				std::stringstream hourStream(hours.at(day));
				hourStream >> hourInt;
				if (hourInt < minWork)
					color(4);
				else if (hourInt > minWork)
					color(2);
				else
					color(fgColor);
				gotoxy(8 + (12 * weekDay), 4 + (4 * week));
				std::cout << std::string(3, ' ');
				gotoxy(8 + (12 * weekDay), 4 + (4 * week));
				std::cout << std::setw(3);
				std::cout << '>' + hours.at(day);
			}
			break;
		case 27: // 27 is escape
			if (day > 1)
			{
				if (hours.at(day).size() == 0)
				{
					hours.at(day) = "0";
					color(4);
				}
				gotoxy(8 + (12 * weekDay), 4 + (4 * week));
				std::cout << std::string(3, ' ');
				gotoxy(8 + (12 * weekDay), 4 + (4 * week));
				std::cout << std::setw(3) << hours.at(day);
				if (weekDay == 0)
				{
					week--;
					weekDay = 6;
				}
				else
					weekDay--;
				day--;
				goto recordHours;
			}
			break;
		case 32: // 32 is space
			break;
		default:
			if (ch >= 48 && ch <= 57)
			{
				std::string newHour = hours.at(day) + ch;
				std::stringstream hourStream(newHour);
				hourStream >> hourInt;
				if (hourInt <= 24 && hourInt >= 0 && hours.at(day).size() < 2 && !(hours.at(day).size() == 1 && hourInt == 0))
				{
					hours.at(day) += ch;
					if (weekDay == 0)
					{
						if (hourInt > 0)
							color(2);
						else
							color(fgColor);
					}
					else if (hourInt < minWork)
						color(4);
					else if (hourInt > minWork)
						color(2);
					else
						color(fgColor);
					gotoxy(8 + (12 * weekDay), 4 + (4 * week));
					std::cout << std::string(3, ' ');
					gotoxy(8 + (12 * weekDay), 4 + (4 * week));
					std::cout << std::setw(3) << '>' + hours.at(day);
				}
				else
				{
					std::stringstream hourStream(hours.at(day));
					hourStream >> hourInt;
				}
			}
		}
		ch = _getch();
	}
	if (hours.at(day).size() == 0)
	{
		hours.at(day) = "0";
		hourInt = 0;
		if (weekDay != 0)
			color(4);
		else
			color(fgColor);
	}
	gotoxy(8 + (12 * weekDay), 4 + (4 * week));
	std::cout << std::string(3, ' ');
	gotoxy(8 + (12 * weekDay), 4 + (4 * week));
	std::cout << std::setw(3) << hours.at(day);
	if (weekDay == 0)
		pay = hourInt * (hourlyRate * minWork);
	else if (hourInt > minWork)
		pay = ((hourInt - minWork) * (hourlyRate * 2)) + (hourInt * hourlyRate);
	else
		pay = hourInt * hourlyRate;
	payTable.at(day - 1) = pay;
	gotoxy(2 + (12 * weekDay), 5 + (4 * week));
	std::cout << std::setw(9) << pay;
	if (day < calDays)
	{
		if (weekDay == 6)
		{
			week++;
			weekDay = 0;
		}
		else
			weekDay++;
		day++;
		goto recordHours;
	}
	int payTotal = 0;
	for (unsigned int i = 0; i < payTable.size(); i++)
	{
		payTotal += payTable.at(i);
	}
	payComputation(payTotal);

	// Write to file
	std::string newFile;
	std::string fileDir = ".\\records\\user\\" + username + "\\";
	std::string newDir = "mkdir" + fileDir;
	std::string recordStr;
	std::fstream record;
	record.open(fileDir + username + ".txt");
	if (!record.is_open())
	{
		system(newDir.c_str());
		std::ofstream record(fileDir + username + ".txt");
		if (record.is_open())
		{
			record << calName;
			record.close();
		}
	}
	else
	{
		record.close();
		std::ofstream newRecord;
		newRecord.open(fileDir + username + ".txt", std::ios::app);
		newRecord << "\n"
				  << calName;
		newRecord.close();
	}
	std::ofstream hourRecord(fileDir + calName + "_hours.txt");
	if (hourRecord.is_open())
	{
		for (unsigned int i = 0; i < hours.size(); i++)
		{
			std::string write = i != hours.size() - 1 ? hours.at(i) + "\n" : hours.at(i);
			hourRecord << write;
		}
		hourRecord.close();
	}
	std::ofstream dataRecord(fileDir + calName + "_data.txt");
	if (dataRecord.is_open())
	{
		dataRecord << minWork << "\n";
		dataRecord << hourlyRate << "\n";
		dataRecord << calDays << "\n";
		dataRecord << calStart;
		dataRecord.close();
	}
}
#endif // !RECORD_H