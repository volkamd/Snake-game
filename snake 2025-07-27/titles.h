#include <iostream>
#include <vector>
#include <Windows.h>

class wall {
private:
	int size_x;
	int size_y;
public:
	wall(int x, int y);

	 void printwall();
	 
	  int getXbord();
	  int getYbord();
	 
};


class point {
private:
	int x;
	int y;
public:
	point(int xx, int yy);
	void change_x_plus();
	void change_x_minus();
	void change_y_plus();
	void change_y_minus();
	int get_x();
	int get_y();
};

class snake {
private:
	std::vector<point> coord;
	char posit = '>';
	HANDLE op = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cPos;
	int speed = 0;
public:
	void setstartposition(wall a);
	void move_press_key(char &go);
	void move();
	void add_piece_of_boody();
	point get_coord_head();
	void getspeed(int &speed);
};

bool check (point head, wall wal);

class food{
private:
	std::vector<point> coordinate;
	
public:
	
	void spawn(wall wal);
	bool check(point head);
	
};

int speed(int value);
