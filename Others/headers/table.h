#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

#ifndef CONSOLE_H
#include "./console.h"
#endif // !CONSOLE_H

#ifndef COLOR_H
#include "./color.h"
#endif // !COLOR_H

using namespace colors;

void top(int width, int columns)
{
	putchar(201);
	for (int i = 1; i < columns; i++)
	{
		repeatChar(width, 205);
		putchar(203);
	}
	repeatChar(width, 205);
	putchar(187);
	std::cout << std::endl;
}
void divider(int width, int columns)
{
	putchar(186);
	for (int i = 1; i < columns; i++)
	{
		std::cout << std::string(width, ' ');
		putchar(186);
	}
	std::cout << std::string(width, ' ');
	putchar(186);
	std::cout << std::endl;
}
void dividerCross(int width, int columns)
{
	putchar(204);
	for (int i = 1; i < columns; i++)
	{
		repeatChar(width, 205);
		putchar(206);
	}
	repeatChar(width, 205);
	putchar(185);
	std::cout << std::endl;
}
void bottom(int width, int columns)
{
	putchar(200);
	for (int i = 1; i < columns; i++)
	{
		repeatChar(width, 205);
		putchar(202);
	}
	repeatChar(width, 205);
	putchar(188);
	std::cout << std::endl;
}
void table(int width, int length, int columns, int rows)
{
	top(width, columns);
	for (int i = 1; i < rows; i++)
	{
		for (int j = 0; j < length; j++)
		{
			divider(width, columns);
		}
		dividerCross(width, columns);
	}
	for (int j = 0; j < length; j++)
	{
		divider(width, columns);
	}
	bottom(width, columns);
}
void heading(int width, int columns)
{
	double space;
	putchar(186);
	std::vector<std::string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	days.resize(columns);
	int daysInAWeek = days.size();
	for (int i = 0; i < daysInAWeek; i++)
	{
		color(bgColor);
		space = days[i].size();
		color(6);
		std::cout << std::string(floor((width - space) / 2), ' ') << days[i] << std::string(ceil((width - space) / 2), ' ');
		color(bgColor);
		putchar(186);
	}
	std::cout << std::endl;
}
void calendar(int columns, int width, int calStart, int calDays)
{
	int week = 0;
	int day = 1;
	int weekDay = calStart;
	system("cls");
	color(bgColor);
	top(width, columns);
	heading(width, columns);
	for (int i = 0; i < 6; i++)
	{
		dividerCross(width, columns);
		for (int j = 0; j < 3; j++)
		{
			divider(width, columns);
		}
	}
	bottom(width, columns);
	color(fgColor);
	for (int i = 1; i <= calDays; i++)
	{
		gotoxy(2 + (12 * weekDay), 3 + (4 * week));
		std::cout << day;
		weekDay++;
		day++;
		if (weekDay == 7)
		{
			weekDay = 0;
			week++;
		}
	}
}

#endif // !TABLE_H