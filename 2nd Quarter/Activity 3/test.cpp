#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <conio.h>

#ifndef CONSOLE_H
#include "./headers/console.h"
#endif // !CONSOLE_H

namespace colors
{
int bgColor = 13;
int fgColor = 7;
} // namespace colors

#ifndef TABLE_H
#include "./headers/table.h"
#endif // !TABLE.H

#ifndef COLOR_H
#include "./headers/color.h"
#endif // !COLOR_H

int main()
{
	system("cls");
start:
	std::vector<std::string> x(5);
	char ch = getch();
	x[2].push_back(ch);
	std::cout << ch;
	goto start;
}