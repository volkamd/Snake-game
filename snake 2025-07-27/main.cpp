#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <Windows.h>
#include <thread>
#include "titles.h"
#include <fstream>


void record( int &score) {
	
	// ;
	std::ifstream in("record.txt");
	std::ofstream out("record.txt");
	int num;
	in >> num;
	if (num < score) {
		out << score;
		out.close();
	}
	in >> num;
	std::cout << "Score " << score << "\n" << "the best score " << num;
	in.close();
}

int main() {

	using namespace std;
	using namespace this_thread;
	using namespace chrono;
	
	
	int score = 10, lvl = 0;
	system("color 25");
	wall a(40, 40);
	std::cout << "Write level of difficult: 1 - 10 \n Write 55 for random level \n Write 0 for growing level \n and press ENTER\n";
	std::cin >>lvl;
	int mon_lvl = lvl;
	if (lvl == 0) {
		mon_lvl = 1;
	}
	lvl = speed(lvl);
	system("cls");
	system("color 75");
	HANDLE op = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cPos;
	cPos.X = 0; cPos.Y = a.getYbord() + 2;
	
	snake zmey;
	food apple;
	a.printwall();
	apple.spawn(a);
	zmey.getspeed(lvl);
	zmey.setstartposition(a);
	SetConsoleCursorPosition(op, cPos);
	std::cout << "score: " << score << " " << "    level: " << mon_lvl;
	while (1) {
		
		
		zmey.move();
		
		if (check(zmey.get_coord_head(), a) == 1) {
			system("cls");
			system("color 72");
			std::cout << "GAME OVER \n";
			record(score);
			return 0;

		}
		if (apple.check(zmey.get_coord_head()) == 1) {
			
			apple.spawn(a);
			zmey.add_piece_of_boody();
			score += 100 * mon_lvl;
			if (score % 1000 == 0 && lvl == 0) {
				
					mon_lvl++;
					int lvl_copy = speed(mon_lvl);
					zmey.getspeed(lvl_copy); 
				
				
			}
			
			printf("\a");
			SetConsoleCursorPosition(op, cPos);
			std::cout << "score: " << score << "    level: " << mon_lvl;
		}
	}

}
