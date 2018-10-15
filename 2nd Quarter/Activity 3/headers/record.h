#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <conio.h>
#include <sstream>
#include <iomanip>

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
	//std::cin >> weekDays;
	std::cout << "Enter your overtime rate: ";
	//std::cin >> overTime;
	std::cout << "Enter your hourly rate: ";
	//std::cin >> hourlyRate;
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
	//std::cin >> calStart;
	std::cout << "Enter how many days the calendar should have: ";
	//std::cin >> calDays;
	weekDays = 8;
	overTime = 300;
	hourlyRate = 250;
	calStart = 1;
	calDays = 31;

	calendar(7, 11, 1, 31);
	int weekDay = calStart;
	int week = 0;
	int day = 1;
	int hourInt;
	char ch;
	std::vector<std::string> hours(calDays + 1);
recordHours:
	gotoxy(8 + (12 * weekDay), 4 + (4 * week));
	color(fgColor);
	std::stringstream hourStream(hours[day]);
	hourStream >> hourInt;
	if (hourInt < weekDays)
		color(4);
	else if (hourInt > weekDays)
		color(2);
	else
		color(fgColor);
	std::cout << std::setw(3) << '>' + hours[day];
	ch = getch();
	while (ch != 13) // 13 is enter
	{
		switch (ch)
		{
		case 8: // 8 is backspace
		case 127:
			if (hours[day].size() != 0)
			{
				hours[day].resize(hours[day].size() - 1);
				std::stringstream hourStream(hours[day]);
				hourStream >> hourInt;
				if (hourInt < weekDays)
					color(4);
				else if (hourInt > weekDays)
					color(2);
				else
					color(fgColor);
				gotoxy(8 + (12 * weekDay), 4 + (4 * week));
				std::cout << std::string(3, ' ');
				gotoxy(8 + (12 * weekDay), 4 + (4 * week));
				std::cout << std::setw(3);
				std::cout << '>' + hours[day];
			}
			break;
		case 27: // 27 is escape
			if (day > 1)
			{
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
				std::string newHour = hours[day] + ch;
				std::stringstream hourStream(newHour);
				hourStream >> hourInt;
				if (hourInt <= 24 && hourInt >= 0 && hours[day].size() < 2 && !(hours[day].size() == 1 && hourInt == 0))
				{
					hours[day] += ch;
					if (hourInt < weekDays)
						color(4);
					else if (hourInt > weekDays)
						color(2);
					else
						color(fgColor);
					gotoxy(8 + (12 * weekDay), 4 + (4 * week));
					std::cout << std::string(3, ' ');
					gotoxy(8 + (12 * weekDay), 4 + (4 * week));
					std::cout << std::setw(3) << '>' + hours[day];
				}
			}
		}
		ch = getch();
	}
	if (hours[day].size() == 0)
	{
		hours[day] = "0";
		color(4);
		gotoxy(8 + (12 * weekDay), 4 + (4 * week));
		std::cout << std::string(3, ' ');
		gotoxy(8 + (12 * weekDay), 4 + (4 * week));
		std::cout << std::setw(3) << hours[day];
	}
	else
	{
		gotoxy(8 + (12 * weekDay), 4 + (4 * week));
		std::cout << std::string(3, ' ');
		gotoxy(8 + (12 * weekDay), 4 + (4 * week));
		std::cout << std::setw(3) << hours[day];
	}
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