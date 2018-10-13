#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>  // various
#include <conio.h>   // _getch
#include <fstream>   // passwords
#include <windows.h> // sleep
#include <algorithm> // transform
#include <string>	 // strings
#include <vector>	 // vector arrays

#ifndef BOX_H
#include "./box.h"
#endif // !BOX_H

#ifndef CONSOLE_H
#include "./console.h"
#endif // !CONSOLE_H

using namespace access;
using namespace boxText;
using namespace colors;

void loginFail()
{
	lines = {"LOGIN SYSTEM MENU", "CURRENT STATUS", "PRESS ANY KEY TO RESTART", "FAILED"};
	boxColors = {fgColor, fgColor, 6, 198};
	state = 0;
	username.resize(0);
	password.resize(0);
	home();
	box();
	getch();
}
void loginPass()
{
	std::string usernameUpper;
	transform(username.begin(), username.end(), back_inserter(usernameUpper), toupper);
	lines = {"LOGIN SYSTEM MENU", "", "LOGGED IN AS " + usernameUpper, "SUCCESS"};
	switch (state)
	{
	case 1:
		lines[1] = "GUEST ACCESS";
		break;
	case 2:
		lines[1] = "USER ACCESS";
		break;
	case 3:
		lines[1] = "ADMIN ACCESS";
	}
	boxColors = {fgColor, fgColor, 6, 160};
	home();
	cls();
	box();
}
void loginMenu()
{
login:
	lines = {"LOGIN SYSTEM MENU", "CURRENT STATUS", "LOGGED OFF", ""};
	boxColors = {fgColor, fgColor, 4, fgColor};
	gotoxy(0, 0);
	cls();
	box();
	std::cout << "Username: " << std::endl;
	std::cout << "Password: " << std::string(16, '-') << "\e[J";
username:
	gotoxy(10 + username.size(), 6);
	char ch;
	ch = getch();
	while (ch != 13) // 13 is enter
	{
		switch (ch)
		{
		case 8: // 8 is backspace
		case 127:
			if (username.size() != 0)
			{
				username.resize(username.size() - 1);
				std::cout << "\b \b";
			}
			break;
		case 27: // 27 is escape
			username.resize(0);
			gotoxy(10, 6);
			std::cout << "\e[K";
			break;
		case 32: // 32 is space
			break;
		default:
			if (username.size() != 16)
			{
				putchar(toupper(ch));
				username += ch;
			}
		}
		ch = getch();
	}
	gotoxy(10 + password.size(), 7);
	ch = getch();
	while (ch != 13) // 13 is enter
	{
		switch (ch)
		{
		case 8: // 8 is backspace
		case 127:
			if (password.size() != 0)
			{
				password.resize(password.size() - 1);
				std::cout << "\b-\b";
			}
			break;
		case 27: // 27 is escape
			goto username;
			break;
		case 32: // 32 is space
			break;
		default:
			if (password.size() != 16)
			{
				password += ch;
				std::cout << '*';
			}
		}
		ch = getch();
	}

	lines = {"LOGIN SYSTEM MENU", "CURRENT STATUS", "LOGGING IN", ""};
	boxColors = {fgColor, fgColor, 6, fgColor};
	std::cout << "\e[H";
	box();
	color(17);
	gotoxy(6, 4);
	for (int j = 0; j < 7; j++)
	{
		Sleep(10);
		std::cout << ".";
	}
	Sleep(2500);
	for (int j = 0; j < 8; j++)
	{
		Sleep(10);
		std::cout << ".";
	}
	Sleep(1500);
	for (int j = 0; j < 5; j++)
	{
		Sleep(10);
		std::cout << ".";
	}
	color(bgColor);

	if (username == "guest")
	{
		state = 1;
		loginPass();
	}
	else
	{
		std::string correctPass;
		std::string fileName = "./login/admin/" + username + ".txt";
		std::ifstream passFile(fileName.c_str());
		if (passFile.is_open())
		{
			getline(passFile, correctPass);
			if (password == correctPass)
			{
				state = 3;
				loginPass();
			}
			else
			{
				loginFail();
				goto login;
			}
		}
		else
		{
			std::string fileName = "./login/user/" + username + ".txt";
			std::ifstream passFile(fileName.c_str());
			if (passFile.is_open())
			{
				getline(passFile, correctPass);
				if (password == correctPass)
				{
					state = 2;
					loginPass();
				}
				else
				{
					loginFail();
					goto login;
				}
			}
			else
			{
				loginFail();
				goto login;
			}
		}
	}
}
#endif // !LOGIN_H