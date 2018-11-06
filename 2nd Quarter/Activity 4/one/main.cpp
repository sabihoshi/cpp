#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
#include "./headers/login.h"
#include "./headers/console.h"

using namespace access;
using namespace boxText;
using namespace colors;

int main()
{
	VT100();
	std::cout << "\e]2;Login System\x07";
	switch (state)
	{
	case -1:
		loginMenu();
		break;
	case 1:
	case 2:
	case 3:
		loginPass();
		break;
	case 0:
		loginFail();
		break;
	}
	int premiumChannels, connections = 1;
	std::cout << "Enter how many premium channels you want > ";
	std::cin >> premiumChannels;
	if (state == 3)
	{
		std::cout << "Enter how many basic service connections > ";
		std::cin >> connections;
	}
	gotoxy(0, 6);
	eos();
	std::cout << "Type: ";
	switch (state)
	{
	case 1:
		std::cout << "Guest" << std::endl;
		break;
	case 2:
		std::cout << "User" << std::endl;
		break;
	case 3:
		std::cout << "Business" << std::endl;
		break;
	default:
		return 1;
	}
	std::cout << "Account No: " << username << std::endl
			  << std::endl
			  << "Formula: (channels x 300) x connections" << std::endl
			  << "Breakdown: " << premiumChannels << " x " << 300 << " = " << premiumChannels * 300 << std::endl
			  << "Connections: " << connections << premiumChannels * 300 << " x " << connections << std::endl
			  << std::endl
			  << "Total amount due: " << (premiumChannels * 300) * connections << "PHP" << std::endl;
	system("pause");
}