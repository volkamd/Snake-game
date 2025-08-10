#include "titles.h"
#include <random>
#include <ctime>
#include <Windows.h>
bool check(point head, wall wal) {
	if (head.get_x() == 0 || head.get_x() == wal.getXbord()) {
		return 1;
	}
	if (head.get_y() == 0 || head.get_y() == wal.getYbord()) {
		return 1;
	}
	return 0;

}

void food::spawn(wall wal) {
	//coordinate = ;
	srand(time(NULL));
	if (coordinate.empty() == 1) {
		this->coordinate.push_back(point(rand() % (wal.getXbord() - 1) + 1, rand() % (wal.getYbord() - 1) + 1));

	}
	else {
		this->coordinate[0] = (point(rand() % (wal.getXbord() - 1) + 1, rand() % (wal.getYbord() - 1) + 1));
	}
	
	HANDLE oop = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cPoss; cPoss.X = coordinate[0].get_x(); cPoss.Y = coordinate[0].get_y();
	
	SetConsoleCursorPosition(oop, cPoss);
	printf("%c", 'A');
}
// прописать еду!!!



bool food::check(point head) {
	if (head.get_x() == coordinate[0].get_x() && head.get_y() == coordinate[0].get_y()) {
		return 1;  // змея съела
	}
	else return false;
}
// если checj дает 1 значит змея съела и надо заспавнить еду. если 0 то ничего. 


int speed(int value) {
	srand(time(0));
	if (value == 55) {
		return rand() % 900 + 100;
	}
	
	if (value == 0) {
		return 1300;
	}
	else {
		if (value >= 10) {
			return 200;
		}
		return 1400 - value * 100;
	}
}
