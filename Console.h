#ifndef CONSOLE_H
#define CONSOLE_H
#pragma once

#include <string>
#include <iostream>
using namespace std;

class Console
{
public:
	Console();
	~Console();
	void Move(int V, int H);
};

extern char map[10][55];
extern int x;
extern int y;

extern int number_of_coins;

extern int health;

extern string dialog;

extern bool dialog_displayed;

extern bool treasure_opened;
extern bool got_key;
extern bool got_key2;

#endif
