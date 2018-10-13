#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

void graph(int weekDays, int overTime, int hourlyRate)
{
	std::string divider = " | ";

	// Output top headings
	std::vector<std::string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int daysInAWeek = days.size();
	for (int day = 0; day < daysInAWeek; day++)
	{
		std::cout << days[day];
		if (day != daysInAWeek - 1)
			std::cout << divider;
	}
	std::cout << std::endl;

	for (int week = 1; week <= 4; week++)
	{
		// Output spaces of Sunday
		std::cout << std::setw((days.at(0)).length()) << ""
				  << divider;

		// Output weekDays (Monday - Friday)
		for (int i = 1; i <= 5; i++)
		{
			std::cout << std::setw((days.at(i)).length())
					  << weekDays << divider;
		}

		// Output overTime (Saturday)
		std::cout << std::setw((days.at(6)).length())
				  << overTime << std::endl;
	}
	std::cout << "Total: " << (weekDays * 5) * 4 + overTime * 4;
	std::cout << std::endl
			  << std::endl;

	// Output top headings
	for (int day = 0; day < 7; day++)
	{
		std::cout << days[day];
		if (day != daysInAWeek - 1)
			std::cout << divider;
	}
	std::cout << std::endl;

	for (int week = 1; week <= 4; week++)
	{
		// Output spaces of Sunday
		std::cout << std::setw((days.at(0)).length()) << ""
				  << divider;

		// Output weekDays
		for (int i = 1; i <= 5; i++)
		{
			std::cout << std::setw((days.at(i)).length())
					  << weekDays * hourlyRate << divider;
		}

		// Output overTime
		std::cout << std::setw((days.at(6)).length())
				  << overTime * hourlyRate << std::endl;
	}
	std::cout << "Total: " << (weekDays * hourlyRate * 5) * 4 + overTime * hourlyRate * 4;
	std::cout << std::endl;
}

#endif // !GRAPH_H
