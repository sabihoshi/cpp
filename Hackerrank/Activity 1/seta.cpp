#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <string>

namespace colors
{
int bgColor = 1;
int fgColor = 7;
} // namespace colors
namespace boxText
{
std::vector<std::string> lines;
std::vector<int> boxColors;
} // namespace boxText

void repeatChar(int n, int ch)
{
	for (int i = 0; i < n; i++)
	{
		putchar(ch);
	}
}
void color(int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
}
void box()
{
	color(colors::bgColor);
	putchar(201);
	repeatChar(30, 205);
	putchar(187);
	std::cout << std::endl;
	for (unsigned int i = 0; i < boxText::lines.size(); i++)
	{
		double space = boxText::lines[i].size();
		putchar(186);
		color(boxText::boxColors[i]);
		std::cout << std::string(ceil((30 - space) / 2), ' ') << boxText::lines[i] << std::string(floor((30 - space) / 2), ' ');
		color(colors::bgColor);
		putchar(186);
		std::cout << std::endl;
	}
	putchar(200);
	repeatChar(30, 205);
	putchar(188);
	std::cout << std::endl;
	color(colors::fgColor);
}
int main()
{
	boxText::lines = {"Hi my name is", "Kao"};
	boxText::boxColors = {2, 4};
	box();
}