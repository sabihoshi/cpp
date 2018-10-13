#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}
void home()
{
	std::cout << "\e[H";
}
void cls()
{
	std::cout << "\e[H";
	std::cout << "\e[J";
}
void eos()
{
	std::cout << "\e[J";
}
void eol()
{
	std::cout << "\e[K";
}
void repeatChar(int n, int ch)
{

	for(int i = 0; i < n; i++)
	{
		putchar(ch);
	}

}
#endif // !CONSOLE_H
