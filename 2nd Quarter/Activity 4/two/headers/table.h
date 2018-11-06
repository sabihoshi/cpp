#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

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
void dividerCrossDown(int width, int columns, int cut)
{
	putchar(204);
	for (int k = 1; k < columns / cut; k++)
	{
		for (int j = 1; j < cut; j++)
		{
			for (int i = 1; i < columns / cut; i++)
			{
				repeatChar(width, 205);
				putchar(203);
			}
			repeatChar(width, 205);
			putchar(206);
		}
		repeatChar(width, 205);
		putchar(203);
	}
	repeatChar(width, 205);
	putchar(185);
	std::cout << std::endl;
}
void dividerCrossUp(int width, int columns, int cut)
{
	putchar(204);
	for (int k = 1; k < columns / cut; k++)
	{
		for (int j = 1; j < cut; j++)
		{
			for (int i = 1; i < columns / cut; i++)
			{
				repeatChar(width, 205);
				putchar(202);
			}
			repeatChar(width, 205);
			putchar(202);
		}
		repeatChar(width, 205);
		putchar(202);
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
void bookHeading(int width, int columns, int rows, int offsetY, const char *line)
{
	gotoxy((1 + columns) + ((width * columns) + ((width - strlen(line)) / 2)), offsetY + 3 + rows);
	std::cout << line;
}
void passBook(int width, int columns, int rows, int cuts, int offsetY, int maxLines)
{
	top((width * cuts) + 1, columns / cuts);
	for (int i = 0; i < rows; i++)
		divider((width * cuts) + 1, columns / cuts);
	dividerCrossDown(width, columns, columns / cuts);
	for (int i = 0; i < rows; i++)
		divider(width, columns);
	dividerCross(width, columns);
	for (int i = 0; i < maxLines + 4; i++)
		divider(width, columns);
	bottom(width, columns);
	color(3);
	gotoxy(2, offsetY + 1);
	std::cout << "Depositors";
	gotoxy(2 + ((width * cuts) + (columns / cuts)), offsetY + 1);
	std::cout << "Account Number";
	bookHeading(20, 0, 3, offsetY, "Date");
	bookHeading(20, 1, 3, offsetY, "Type");
	bookHeading(20, 2, 3, offsetY, "Amount");
	bookHeading(20, 3, 3, offsetY, "Balance");
}

#endif // !TABLE_H