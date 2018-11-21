#include <iostream>  // various
#include <conio.h>   // getch
#include <fstream>   // passwords
#include <windows.h> // sleep
#include <algorithm> // transform
#include <string>	// strings
#include <vector>	// vector arrays

namespace colors
{
int bgColor = 1;
int fgColor = 7;
} // namespace colors
namespace access
{
std::string username = "";
std::string password = "";
int state = -1;
} // namespace access
namespace boxText
{
std::vector<std::string> lines;
std::vector<int> boxColors;
} // namespace boxText

#include "./headers/color.h"
#include "./headers/record.h"
#include "./headers/login.h"
#include "./headers/console.h"
#include "./headers/graph.h"

using namespace access;
using namespace boxText;
using namespace colors;

int main()
{
	// SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	// ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	VT100();
	std::cout << "\033]2;Login System\x07";
start:
	switch (state)
	{
	case -1:
		loginMenu();
		break;
	case 1:
	case 2:
		loginPass();
		break;
	case 0:
		loginFail();
		break;
	}
	std::cout << std::endl;
	char choice;
	lines = {"Record a salary", "View other records (WIP)", "Change color", "Logout"};
	consoleSize(32, (lines.size() + 2) + 10, true);
	options(lines);
	color(12);
	std::cout << "[X] ";
	color(8);
	std::cout << "Exit" << std::endl;
	color(fgColor);
	std::cout << std::endl
			  << "Enter your choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case '1':
		if (state == 1)
		{
			std::cout << "You can't record as a guest!" << std::endl;
			_getch();
			goto start;
		}
		record();
		_getch();
		goto start;
		break;
	case '2':
		graph();
		_getch();
		goto start;
		break;
	case '3':
		changeColor();
		goto start;
		break;
	case '4':
		username.resize(0);
		password.resize(0);
		state = -1;
		loginMenu();
		goto start;
		break;
	case 'x':
	case 'X':
		return 0;
		break;
	default:
		goto start;
		break;
	}
}