#include "stdafx.h"
#include "enemy.h"
#include "Console.h"
#include "Windows.h"

//int Ex = 5;
//int Ey = 5;

enemy::enemy()
{
}


enemy::~enemy()
{
}

void enemy::Move(int V, int H)
{
	int Ey2 = Ey + V;
	int Ex2 = Ex + H;

	if (map[Ey2][Ex2] == '@')
	{
		health -= 20;
	}

	if (map[Ey][Ex2] == ' '
		|| map[Ey][Ex2] == '@')
	{
		map[Ey][Ex] = ' ';
		Ex += H;
		map[Ey][Ex] = enemy_symbol;
	}
	if (map[Ey2][Ex] == ' '
		|| map[Ey][Ex2] == '@')
	{
		map[Ey][Ex] = ' ';
		Ey += V;
		map[Ey][Ex] = enemy_symbol;
	}
}

int enemy::Init(int V, int H)
{
	//map[V][H] = enemy_symbol;
	if (!location_set)
	{
		Ex = H;
		Ey = V;
		map[Ey][Ex] = enemy_symbol;
		location_set = true;
	}

	if (Ey - y < 5 && Ey + y > 5 
		&& Ex + x > 5 && Ex - x < 5)
	{
		sighted_player = true;
	}

	if (sighted_player)
	{
		if (y < Ey)
		{
			enemy::Move(-1, 0);
		}
		else if (y > Ey)
		{
			enemy::Move(1, 0);
		}
		else if (x > Ex)
		{
			enemy::Move(0, 1);
		}
		else if (x < Ex)
		{
			enemy::Move(0, -1);
		}
	}

	return 0;
}