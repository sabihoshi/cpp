#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>
#include <algorithm>
#include <cctype>
#include <locale>

// trim from start (in place)
static inline void ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
				return !std::isspace(ch);
			}));
}

// trim from end (in place)
static inline void rtrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
				return !std::isspace(ch);
			})
				.base(),
			s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s)
{
	ltrim(s);
	rtrim(s);
}

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

// Enable Terminal Virtual Processing (VT100 Codes)
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

void VT100()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
}

void gotoxyVT(int x, int y)
{
	VT100();
	std::string str = "\033[" + std::to_string(y) + ";" + std::to_string(x) + "H";
	std::cout << str;
}

void home()
{
	VT100();
	std::cout << "\033[H";
}

void cls()
{
	VT100();
	std::cout << "\033[H";
	std::cout << "\033[J";
}

void eos()
{
	VT100();
	std::cout << "\033[J";
}

void eol()
{
	VT100();
	std::cout << "\033[K";
}

void repeatChar(int n, int ch)
{
	for (int i = 0; i < n; i++)
	{
		putchar(ch);
	}
}

#endif // !CONSOLE_H