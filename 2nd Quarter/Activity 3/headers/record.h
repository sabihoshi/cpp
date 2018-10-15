#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <conio.h>
#include <sstream>

#ifndef GRAPH_H
#include "graph.h"
#endif // !GRAPH_H

#ifndef TABLE_H
#include "./table.h"
#endif // !TABLE.H

#ifndef COLOR_H
#include "./color.h"
#endif // !COLOR_H

using namespace colors;

void record()
{
	int weekDays, overTime, hourlyRate, calStart, calDays;
	std::cout << "Hours needed per day: ";
	std::cin >> weekDays;
	std::cout << "Enter your overtime rate: ";
	std::cin >> overTime;
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

	calendar(7, 11, 1, 31);
	int weekDay = calStart;
	int week = 0;
	int day = 1;
	int hourInt;
	char ch;
	std::vector<std::string> hours(calDays + 1);
recordHours:
	gotoxy(10 + (12 * weekDay), 4 + (4 * week));
	color(fgColor);
	std::cout << ">";
	ch = getch();
	while (ch != 13) // 13 is enter
	{
		switch (ch)
		{
		case 8: // 8 is backspace
		case 127:
			if (hours[day].size() != 0)
			{
				std::cout << std::string(hours[day].size() + 1, '\b') << std::string(hours[day].size() + 1, ' ') << std::string(hours[day].size(), '\b') << ">";
				hours[day].resize(hours[day].size() - 1);
				std::stringstream hourStream(hours[day]);
				hourStream >> hourInt;
				if (hourInt < weekDays)
					color(4);
				else if (hourInt > weekDays)
					color(2);
				else
					color(fgColor);
				std::cout << hours[day];
			}
			break;
		case 32: // 32 is space
			break;
		default:
			if (ch >= 48 && ch <= 57)
			{
				std::string newHour = hours[day] + ch;
				std::stringstream hourStream(newHour);
				hourStream >> hourInt;
				if (hourInt <= 24 && hourInt >= 0 && hours[day].size() < 2)
				{
					hours[day] += (ch);
					if (hourInt < weekDays)
						color(4);
					else if (hourInt > weekDays)
						color(2);
					else
						color(fgColor);
					std::cout << std::string(hours[day].size() + 1, '\b') << ">" << hours[day];
				}
			}
		}
		ch = getch();
	}
	if (hours[day].size() == 0)
	{
		hours[day] = "0";
		color(4);
		std::cout << std::string(hours[day].size() + 1, '\b') << " 0";
	}
	else
		std::cout << std::string(hours[day].size() + 1, '\b') << ' ';
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
}
#endif // !RECORD_H