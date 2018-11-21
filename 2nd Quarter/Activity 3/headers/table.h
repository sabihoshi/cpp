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

double sssCompensation(double &revenue)
{
	std::vector<int> sssCredit = {15750, 15500, 15000, 14500, 14000, 13500, 13000, 12500, 12000, 11500, 11000, 10500, 10000, 9500, 9000, 8500, 8000, 7500, 7000, 6500, 6000, 5500, 5000, 4500, 4000, 3500, 3000, 2500, 2000, 1500, 1000};
	std::vector<double> sssRate = {581.30, 563.20, 545.00, 526.80, 508.70, 490.50, 472.30, 454.20, 436.00, 417.80, 399.70, 381.50, 363.30, 345.20, 327.00, 308.80, 290.70, 272.50, 254.30, 236.20, 218.00, 199.80, 181.70, 163.50, 145.30, 127.20, 109.00, 90.80, 72.70, 54.50, 36.30};
	for (unsigned int i = 0; i < sssCredit.size(); i++)
	{
		if (revenue >= sssCredit.at(i))
		{
			revenue -= sssRate.at(i);
			return sssRate.at(i);
		}
	}
	return 0;
}

void payComputation(int payTotal)
{
	int annualPay = payTotal * 12;
	float taxRate = 0, taxFixed = 0;
	if (annualPay >= 8000000)
	{
		taxFixed = 2410000 / 12;
		taxRate = 0.35;
	}
	else if (annualPay >= 2000000)
	{
		taxFixed = 490000 / 12;
		taxRate = 0.32;
	}
	else if (annualPay >= 800000)
	{
		taxFixed = 130000 / 12;
		taxRate = 0.30;
	}
	else if (annualPay >= 400000)
	{
		taxFixed = 30000 / 12;
		taxRate = 0.25;
	}
	else if (annualPay >= 250000)
	{
		taxRate = 0.20;
	}
	double incomeTax = ((payTotal - taxFixed) * taxRate) + taxFixed;
	double revenue = payTotal - incomeTax;
	double sssContribution = sssCompensation(revenue);
	int tableFill = 30;
	std::string taxText = "Income Tax: (" + std::to_string((int)(taxRate * 100)) + "\% + " + std::to_string((int)taxFixed) + ")";
	consoleOffset(0, 5, true);
	gotoxy(0, 27);
	color(fgColor);
	std::cout << std::left << std::setw(tableFill) << "Total:" << std::right << std::setw(12) << payTotal << "PHP" << std::endl
			  << std::endl
			  << std::left << std::setw(tableFill) << taxText << std::right << std::setw(12) << incomeTax << "PHP" << std::endl
			  << std::left << std::setw(tableFill) << "SSS Contribution:" << std::right << std::setw(12) << sssContribution << "PHP" << std::endl
			  << std::left << std::setw(tableFill) << "Revenue:" << std::right << std::setw(12) << revenue << "PHP" << std::endl;
}

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