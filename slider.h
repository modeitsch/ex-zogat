#pragma once
class slider
{
public:
	slider();
	~slider();
	void Move(int V, int H);
	int Init_Hor(int V, int H);
	int Init_Ver(int V, int H);
	int Sy; int Sx;

	char slider_symbol = '|';
	bool moved = false;
	bool location_set = false;
};

//extern bool moved;
//extern int Sx;
//extern int Sy;