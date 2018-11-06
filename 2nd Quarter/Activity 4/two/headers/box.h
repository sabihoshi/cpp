#ifndef BOX_H
#define BOX_H

#include <vector>
#include <iostream>
#include <math.h>
#include <stdio.h>

#ifndef COLOR_H
#include "color.h"
#endif // !COLOR_H

#ifndef CONSOLE_H
#include "./console.h"
#endif // !CONSOLE_H

using namespace boxText;
using namespace colors;

void box()
{
	color(bgColor);
	putchar(201);
	repeatChar(30, 205);
	putchar(187);
	std::cout << std::endl;
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		double space = lines[i].size();
		putchar(186);
		color(boxColors[i]);
		std::cout << std::string(ceil((30 - space) / 2), ' ') << lines[i] << std::string(floor((30 - space) / 2), ' ');
		color(bgColor);
		putchar(186);
		std::cout << std::endl;
	}
	putchar(200);
	repeatChar(30, 205);
	putchar(188);
	std::cout << std::endl;
	color(fgColor);
}
void options(std::vector<std::string> lines)
{
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		color(bgColor);
		std::cout << "[" << i + 1 << "] ";
		color(fgColor);
		std::cout << lines[i] << std::endl;
	}
}

#endif // !BOX_H