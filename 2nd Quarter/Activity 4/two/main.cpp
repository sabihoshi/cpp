#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <locale>

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
#include "./headers/table.h"
#include "./headers/json.h"

using namespace access;
using namespace boxText;
using namespace colors;
using json = nlohmann::json;

class comma_numpunct : public std::numpunct<char>
{
  protected:
	virtual char do_thousands_sep() const
	{
		return ',';
	}

	virtual std::string do_grouping() const
	{
		return "\03";
	}
};


int main()
{
	// Enable VT100 Escape Codes processing
	VT100();
	std::cout << "\e]2;Bank Record System\x07";
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
	gotoxy(0, 6);
	eos();
	json data = json();
	std::string depositor, accountNumber, startingBalance = "0", buffer[3];
	std::ifstream record("./records/" + username + ".txt");
	if (record.good())
	{
		std::getline(record, depositor);
		std::getline(record, accountNumber);
		std::getline(record, startingBalance);
		int index = 0;
		while (getline(record, buffer[0]))
		{
			getline(record, buffer[1]);
			getline(record, buffer[2]);
			data[index] = {
				buffer[0],
				buffer[1],
				buffer[2]};
			index++;
		}
	}
	int width = 20, columns = 4, rows = 3, cuts = 2, offsetX = 1, offsetY = 6, jump;
	passBook(width, columns, rows, cuts, offsetY, data.size() + 1);
	jump = 0;
	gotoxy(offsetX + (columns / cuts * jump) + (jump * width * cuts), offsetY + 2);
	std::cout << std::setw(offsetX + (columns / cuts * jump) + (width * cuts) / 2) << depositor;
	jump = 1;
	gotoxy(offsetX + (columns / cuts) + (jump * width * cuts), offsetY + 2);
	std::cout << std::setw(offsetX + (columns / cuts) + (width * cuts) / 2) << accountNumber;

	// Enable grouping by thousands
	std::locale comma_locale(std::locale(), new comma_numpunct());
	std::cout.imbue(comma_locale);

	jump = 1;
	gotoxy(offsetX + jump + (jump * width), offsetY + 10);
	std::cout << std::setw(width - offsetX) << "Forwarded Balance";
	jump = 3;
	gotoxy(offsetX + jump + (jump * width), offsetY + 10);
	std::cout << std::setw(width - offsetX) << startingBalance;
	double balance = std::stoi(startingBalance);
	for (unsigned int j = 0; j < data.size(); j++)
	{
		for (unsigned int i = 0; i < data[j].size(); i++)
		{
			std::string str = data[j][i];
			gotoxy(offsetX + i + (i * width), offsetY + 12 + j);
			if (i == 0)
				std::cout << std::setw(width - ((strlen(str.c_str()) / 2) + offsetX) - offsetX);
			else
				std::cout << std::setw(width - offsetX);
			color(fgColor);
			std::cout << str;
		}
		std::string str = data[j][1];
		std::string value = data[j][2];
		double amount = std::stod(value);
		if (str == "Interest")
			balance += balance * (amount / 100);
		else if (str == "Withdraw")
			balance -= amount;
		else if (str == "Deposit")
			balance += amount;
		jump = 3;
		gotoxy(offsetX + jump + (jump * width), offsetY + 12 + j);
		color(2);
		std::cout << std::fixed << std::setprecision(2) << std::setw(width - offsetX) << balance;
	}
	std::cin.get();
}