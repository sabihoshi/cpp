// A program to demonstrate the use of stringstream
#include <iostream>
#include <conio.h>
#include <sstream>
#include <iomanip>
#include <string>

namespace colors
{
int bgColor = 1;
int fgColor = 7;
} // namespace colors

#include "./headers/console.h"
#include "./headers/table.h"

using namespace std;
using namespace colors;

int main()
{
	system("cls");
	calendar(7, 3, 1, 31);
	gotoxy(0, 30);
}