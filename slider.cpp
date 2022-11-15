#include "stdafx.h"
#include "slider.h"
#include "Console.h"

//int Sx = 1;
//int Sy = 1;
//bool moved = false;

slider::slider()
{
}


slider::~slider()
{
}

void slider::Move(int V, int H)
{
	int Sy2 = Sy + V;
	int Sx2 = Sx + H;

	if (map[Sy][Sx2] == ' ')
	{
		map[Sy][Sx] = ' ';
		Sx += H;
		map[Sy][Sx] = slider_symbol;
	}
	if (map[Sy2][Sx] == ' ')
	{
		map[Sy][Sx] = ' ';
		Sy += V;
		map[Sy][Sx] = slider_symbol;
	}
}

int slider::Init_Hor(int V, int H)
{
	if (!location_set)
	{
		Sx = H;
		Sy = V;
		map[Sy][Sx] = slider_symbol;
		location_set = true;
	}

	//map[V][H] = slider_symbol;
	//Sx = H;
	//Sy = V;
	//map[Sy][Sx] = slider_symbol;

	if(moved)
	{
		slider::Move(0, 1);
		moved = false;
	}
	else if (!moved)
	{
		slider::Move(0, -1);
		moved = true;
	}

	return 0;
}

int slider::Init_Ver(int V, int H)
{
	if (!location_set)
	{
		Sx = H;
		Sy = V;
		map[Sy][Sx] = slider_symbol;
		location_set = true;
	}
	//map[V][H] = slider_symbol;
	//Sx = H;
	//Sy = V;
	//map[Sy][Sx] = slider_symbol;

	if (moved)
	{
		slider::Move(1, 0);
		moved = false;
	}
	else if (!moved)
	{
		slider::Move(-1, 0);
		moved = true;
	}

	return 0;
}