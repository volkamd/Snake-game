#include "titles.h"
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <chrono>
#include <thread>
#pragma once

void snake::add_piece_of_boody(){
	if (this->posit == 'A') {
		this->coord.push_back(point(this->coord.back().get_x(), this->coord.back().get_y() + 1));
	}
	if (this->posit == '>') {
		this->coord.push_back(point(this->coord.back().get_x() - 1, this->coord.back().get_y()));
	}
	if (this->posit == 'v') {
		this->coord.push_back(point(this->coord.back().get_x() + 1, this->coord.back().get_y() - 1));
	}
	if (this->posit == '<') {
		this->coord.push_back(point(this->coord.back().get_x() + 1, this->coord.back().get_y()));
	}
	HANDLE op;
	COORD cPos;
	op = GetStdHandle(STD_OUTPUT_HANDLE);
	cPos.X = this->coord[coord.size()-1].get_x();
	cPos.Y = this->coord[coord.size() - 1].get_y();
	SetConsoleCursorPosition(op, cPos);
	printf("%c", '*');

}


void snake::move() {  
	
		
		if (_kbhit() != 0) {
			char go = _getch();
			move_press_key(go);
		}
		else {
			if (posit == '>') {
				cPos.X = coord[0].get_x();
				cPos.Y = coord[0].get_y();
				SetConsoleCursorPosition(op,cPos);
				printf("%c", ' ');
				for (int i = 0; i < coord.size() - 1; i++) {
					coord[i] = coord[i + 1.0];
				}
				coord[coord.size() - 1].change_x_plus();
				cPos.X = coord[coord.size() - 1].get_x();
				cPos.Y = coord[coord.size() - 1].get_y();
				SetConsoleCursorPosition(op, cPos);
				printf("%c", '*');
			}
			if (posit == 'A') {
				
				cPos.X = coord[0].get_x();
				cPos.Y = coord[0].get_y();
				SetConsoleCursorPosition(op, cPos);
				printf("%c", ' ');
				for (int i = 0; i < coord.size() - 1; i++) {
					coord[i] = coord[i + 1.0];
				}
				coord[coord.size() - 1].change_y_minus();
				cPos.X = coord[coord.size() - 1].get_x();
				cPos.Y = coord[coord.size() - 1].get_y();
				SetConsoleCursorPosition(op, cPos);
				printf("%c", '*');
			}
			if (posit == 'v') {
				cPos.X = coord[0].get_x();
				cPos.Y = coord[0].get_y();
				SetConsoleCursorPosition(op, cPos);
				printf("%c", ' ');
				for (int i = 0; i < coord.size() - 1; i++) {
					coord[i] = coord[i + 1.0];
				}
				coord[coord.size() - 1].change_y_plus();
				cPos.X = coord[coord.size() - 1].get_x();
				cPos.Y = coord[coord.size() - 1].get_y();
				SetConsoleCursorPosition(op, cPos);
				printf("%c", '*');
			}
			if (posit == '<') {
				cPos.X = coord[0].get_x();
				cPos.Y = coord[0].get_y();
				SetConsoleCursorPosition(op, cPos);
				printf("%c", ' ');
				for (int i = 0; i < coord.size() - 1; i++) {
					coord[i] = coord[i + 1.0];
				}
				coord[coord.size() - 1].change_x_minus();
				cPos.X = coord[coord.size() - 1].get_x();
				cPos.Y = coord[coord.size() - 1].get_y();
				SetConsoleCursorPosition(op, cPos);
				printf("%c", '*');
			}

			
			
		}

		std::chrono::milliseconds timespan(speed); 
		std::this_thread::sleep_for(timespan);
	//}
}

void snake::move_press_key(char &go) {
	if ((go == 'D' || go == 'd' || go == 'â' || go == 'Â') && this->posit != '<') {
		this->posit = '>';
	}
	if ((go == 'û' || go == 'Û' || go == 's' || go == 'S') && this->posit != 'A') {
		this->posit = 'v';
	}
	if ((go == 'A' || go == 'a' || go == 'ô' || go == 'Ô') && this->posit != '>') {
		this->posit = '<';
	}
	if ((go == 'Ö' || go == 'ö' || go == 'W' || go == 'w') && this->posit != 'v') {
		this->posit = 'A';
	}

}

void snake::setstartposition(wall a) {
	this->coord.push_back(point(a.getXbord()/2, a.getYbord()/2));
	this->coord.push_back(point(a.getXbord() / 2 + 1, a.getYbord() / 2));
	this->coord.push_back(point(a.getXbord() / 2 + 2, a.getYbord() / 2));
	this->cPos.X = this->coord[0].get_x();
	this->cPos.Y = this->coord[0].get_y();
	SetConsoleCursorPosition(op, cPos);
	std::cout << "***";
	

}

point snake::get_coord_head() {
	return this->coord[coord.size() - 1];
}

void snake::getspeed(int &sped) {
	this->speed = sped;
}
