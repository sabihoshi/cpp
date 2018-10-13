#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <windows.h>
#include <iostream>

#ifndef CONSOLE_H
#include "./console.h"
#endif // !CONSOLE_H

using namespace colors;

void color(int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
}

void changeColor()
{
	cls();
	color(0);
	std::cout << "0 = Black"
			  << "     ";
	color(8);
	std::cout << "8 = Gray" << std::endl;
	color(1);
	std::cout << "1 = Blue"
			  << "      ";
	color(9);
	std::cout << "9 = Light Blue" << std::endl;
	color(2);
	std::cout << "2 = Green"
			  << "     ";
	color(10);
	std::cout << "10 = Light Green" << std::endl;
	color(3);
	std::cout << "3 = Aqua"
			  << "      ";
	color(11);
	std::cout << "11 = Light Aqua" << std::endl;
	color(4);
	std::cout << "4 = Red"
			  << "       ";
	color(12);
	std::cout << "12 = Light Red" << std::endl;
	color(5);
	std::cout << "5 = Purple"
			  << "    ";
	color(13);
	std::cout << "13 = Light Purple" << std::endl;
	color(6);
	std::cout << "6 = Yellow"
			  << "    ";
	color(14);
	std::cout << "14 = Light Yellow" << std::endl;
	color(7);
	std::cout << "7 = White"
			  << "     ";
	color(15);
	std::cout << "15 = Bright White" << std::endl
			  << std::endl;
	color(bgColor);
	std::cout << "Choose bgColor & fgColor: ";
	std::cin >> bgColor >> fgColor;
	color(fgColor);
	system("cls");
}
#endif // !COLOR_H