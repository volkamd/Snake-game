#include "titles.h"
#include <string>
#include <iostream>

#pragma once

point::point(int xx, int yy) {
	this->x = xx; this->y = yy;
}
int point::get_x() {
	return this->x;
}
int point::get_y() {
	return this->y;
}
void point::change_x_plus() {
	this->x++;
}
void point:: change_x_minus() {
	this->x--;
}
void point::change_y_plus() {
	this->y++;
}
void point::change_y_minus() {
	this->y--;
}
wall::wall(int x, int y) {
	this->size_x = x;
	this->size_y = y;
}

 int wall::getXbord() {
	return this->size_x;
 }

 int wall::getYbord() {
	return this->size_y;
 }



void wall::printwall() {
	using namespace std;
	std::string a (this->size_x, '#');
	std::string b(1, '#'); b.append( this->size_x - 1.0, ' '); b.append(1, '#');
	std::cout << a << "\n";
	
	for (int i = 0; i < this->size_y; i++) {
		std::cout << b << "\n";
	}
	std::cout << a;
	
}


