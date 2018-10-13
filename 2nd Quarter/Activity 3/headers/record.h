#ifndef RECORD_H
#define RECORD_H

#include <iostream>

#ifndef GRAPH_H
#include "graph.h"
#endif // !GRAPH_H

#ifndef TABLE_H
#include "./table.h"
#endif // !TABLE.H

#ifndef COLOR_H
#include "./color.h"
#endif // !COLOR_H

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
	int week = 0;
	int day = 1;
	int weekDay = calStart;
	char ch;
	std::string input;
	std::vector<std::string>
		hours;
recordHours:
	gotoxy(10 + (12 * weekDay), 4 + (4 * week));
	color(fgColor);
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
				hours[day] = input;
				std::cout << ' ';
			}
			break;
		case 27: // 27 is escape
			hours[day].resize(0);
			gotoxy(10, 6);
			std::cout << "\e[K";
			break;
		case 32: // 32 is space
			break;
		default:
			if (hours[day].size() != 16)
			{
				std::cout << "\b\b" << ch;
				hours[day] += std::to_string(ch);
			}
		}
		ch = getch();
	}
	if (day < calDays)
	{
		goto recordHours;
		day++;
	}
}
#endif // !RECORD_H