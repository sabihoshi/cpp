#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>
#include <algorithm>
#include <cctype>
#include <locale>
#include <cmath>

// Trim from start (in place)
static inline void ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
				return !std::isspace(ch);
			}));
}

// Trim from end (in place)
static inline void rtrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
				return !std::isspace(ch);
			})
				.base(),
			s.end());
}

// Trim from both ends (in place)
static inline void trim(std::string &s)
{
	ltrim(s);
	rtrim(s);
}

// Moving the cursor position
void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

// Getting the size of the screen
void GetDesktopResolution(int &horizontal, int &vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
}

// Output in the middle
/* void coutCenter(std::vector<std::string> lines)
{
	int horizontal = 0, vertical = 0;
	GetDesktopResolution(horizontal, vertical);
	for(unsigned int = 0; i < lines.size(); i++)
	{
		double space = lines[i].size();
		std::cout <<std::string(ceil((ceil(horizontal/16) - space) / 2), ' ') << lines.[i];
		std::cout << std::endl;
	}
} */
// Make the console in the middle
void consoleCenter()
{
	int horizontal = 0, vertical = 0;
	GetDesktopResolution(horizontal, vertical);
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	int width = r.right - r.left;
	int height = r.bottom - r.top;
	r.left = floor((horizontal - width) / 2);
	r.top = floor((vertical - height) / 2);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Resizing console window
void consoleSize(int width, int height, bool center)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, (width * 8), (height * 16) + 42, TRUE);

	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	COORD buffer;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &SBInfo);

	buffer.X = width;
	buffer.Y = height;
	SetConsoleScreenBufferSize(hOut, buffer);

	MoveWindow(console, r.left, r.top, (width * 8) + 16, (height * 16) + 48, TRUE);

	if (center)
		consoleCenter();
}

// Offsetting the size of the console
void consoleOffset(int width, int height, bool center)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, (r.right - r.left) + (width * 8), (r.bottom - r.top) + (height * 16), TRUE);

	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	COORD buffer;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hOut, &SBInfo);
	buffer.X = width;
	buffer.Y = height;

	SetConsoleScreenBufferSize(hOut, buffer);

	MoveWindow(console, r.left, r.top, (r.right - r.left) + (width * 8), (r.bottom - r.top) + (height * 16), TRUE);

	if (center)
		consoleCenter();
}

// Changing the position of the console window
void consolePos(int x, int y)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, x, y, r.right, r.bottom, TRUE);
}

// Enabling VT100 escape codes processing
void VT100()
{
// Make sure key is defined
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
}

// Move cursor position using escape codes
void gotoxyVT(int x, int y)
{
	VT100();
	std::string str = "\033[" + std::to_string(y) + ";" + std::to_string(x) + "H";
	std::cout << str;
}

// Move cursor to top
void home()
{
	VT100();
	std::cout << "\033[H";
}

// Clear screen
void cls()
{
	VT100();
	std::cout << "\033[H";
	std::cout << "\033[J";
}

// Clear from cursor to end of screen
void eos()
{
	VT100();
	std::cout << "\033[J";
}

// Clear from cursor to end of line
void eol()
{
	VT100();
	std::cout << "\033[K";
}

// Repeat character n times
void repeatChar(int n, int ch)
{
	for (int i = 0; i < n; i++)
	{
		putchar(ch);
	}
}

#endif // !CONSOLE_H