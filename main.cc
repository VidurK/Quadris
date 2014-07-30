#include <iostream>
#include <string>
#include <sstream>
#include "window.h"
#include "quadris.h"
#include <stdlib.h>

using namespace std;

void drawGUI(Quadris *quadris, Xwindow *w) {	
	char block;
	w->fillRectangle(0, 0, 210, 10, Xwindow::Black);
	w->fillRectangle(0, 0, 10, 370, Xwindow::Black);
	w->fillRectangle(210, 0, 10, 370, Xwindow::Black);
	w->fillRectangle(0, 370, 220, 10, Xwindow::Black);
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 10; j++) {
			block = (((quadris->grid)->td)->theDisplay)[i][j];
			if (block == ' ') {
				w->fillRectangle(10 + j*20, 10 + i*20, 20, 20, Xwindow::White);
			} else if (block == 'I') {
				w->fillRectangle(10 + j*20, 10 + i*20, 20, 20, Xwindow::Blue);
			} else if (block == 'T') {
				w->fillRectangle(10 + j*20, 10 + i*20, 20, 20, Xwindow::Red);
			} else if (block == 'L') {
				w->fillRectangle(10 + j*20, 10 + i*20, 20, 20, Xwindow::Blue);
			} else if (block == 'J') {
				w->fillRectangle(10 + j*20, 10 + i*20, 20, 20, Xwindow::Black);
			} else if (block == 'O') {
				w->fillRectangle(10 + j*20, 10 + i*20, 20, 20, Xwindow::Black);
			} else if (block == 'S') {
				w->fillRectangle(10 + j*20, 10 + i*20, 20, 20, Xwindow::Green);
			} else if (block == 'Z') {
				w->fillRectangle(10 + j*20, 10 + i*20, 20, 20, Xwindow::Red);
			}
		}
	}
	
	w->fillRectangle(222, 75, 150, 150, Xwindow::White);
	string text;
	string message;
	
	stringstream ss;
	ss << (quadris->level);
	ss >> text;
	message = "Level: " + text;
	text = "";
	w->drawString(225, 100, message);
	
	stringstream ss1;
	ss1 << (quadris->score);
	ss1 >> text;
	message = "Score: " + text;
	text = "";
	w->drawString(225, 115, message);
	
	stringstream ss2;
	ss2 << (quadris->highscore);
	ss2 >> text;
	message = "Highscore: " + text;
	text = "";
	w->drawString(225, 130, message);
	
	
	w->drawString(225, 145, "Next: ");
	
	
	char nextBlock = (((quadris->grid)->next)->getTypeBlock());

	if (nextBlock == 'J') {
		w->fillRectangle(225,150,20,20, Xwindow::Red);
		w->fillRectangle(245,150,20,20, Xwindow::Red);
		w->fillRectangle(245,170,20,20, Xwindow::Red);
		w->fillRectangle(245,190,20,20, Xwindow::Red);
	}
	else if (nextBlock == 'I') {
		w->fillRectangle(225,150,20,20, Xwindow::Red);
		w->fillRectangle(225,170,20,20, Xwindow::Red);
		w->fillRectangle(225,190,20,20, Xwindow::Red);
		w->fillRectangle(225,210,20,20, Xwindow::Red);
	}
	else if (nextBlock == 'T') {
		w->fillRectangle(225,150,20,20, Xwindow::Red);
		w->fillRectangle(245,150,20,20, Xwindow::Red);
		w->fillRectangle(265,150,20,20, Xwindow::Red);
		w->fillRectangle(245,170,20,20, Xwindow::Red);
	}
	else if (nextBlock == 'S') {
		w->fillRectangle(225,170,20,20, Xwindow::Red);
		w->fillRectangle(245,170,20,20, Xwindow::Red);
		w->fillRectangle(245,150,20,20, Xwindow::Red);
		w->fillRectangle(265,150,20,20, Xwindow::Red);
	}
	else if (nextBlock == 'Z') {
		w->fillRectangle(225,150,20,20, Xwindow::Red);
		w->fillRectangle(245,150,20,20, Xwindow::Red);
		w->fillRectangle(245,170,20,20, Xwindow::Red);
		w->fillRectangle(265,170,20,20, Xwindow::Red);
	}
	else if (nextBlock == 'O') {
		w->fillRectangle(225,150,20,20, Xwindow::Red);
		w->fillRectangle(225,170,20,20, Xwindow::Red);
		w->fillRectangle(245,150,20,20, Xwindow::Red);
		w->fillRectangle(245,170,20,20, Xwindow::Red);;
	}
	else if (nextBlock == 'L') {
		w->fillRectangle(225,150,20,20, Xwindow::Red);
		w->fillRectangle(225,170,20,20, Xwindow::Red);
		w->fillRectangle(225,190,20,20, Xwindow::Red);
		w->fillRectangle(245,190,20,20, Xwindow::Red);
	}
		
}


int main(int argc, char *argv[]) {
	
	cout << "~~~ WELCOME TO QUADRIS! ~~~" << endl;
	cout << "~~ TYPE 'help' FOR COMMANDS ~~" << endl;

	
	int seed = 0;
	int level = 0;
	bool notGUI = false;
	string script = "";
	
	for (int i = 0; i < (argc); i++) {
		string temp = argv[i];
		if (temp == "-text") {
			cout << "yop" << endl;
			notGUI = true;
		} else if (temp == "-seed") {
			i++;
			stringstream ss(argv[i]);
			ss >> seed;
		} else if (temp == "-scriptfile") {
			i++;
			script = argv[i];
		} else if (temp == "-startlevel") {
			i++;
			stringstream ss(argv[i]);
			ss >> level;
		}
	}
	Quadris *quadris = new Quadris(level, seed, script); // Quadris constructor should intialize grid, textdisplay
	
	
	char c;
	int times;
	string input;
	string cmd;
	
	quadris->display();
	if (!notGUI) {		
		Xwindow w(500, 500);
		drawGUI(quadris, &w);
		
		while (cin >> input) {
			/*if (quadris->checkLose()) {
				break;
			} */
				
			c = input[0];
			if ((c >= '0') && (c <= '9')) {
				times = c - '0';
				cmd = input.substr(1);
			} else {
				times = 1;
				cmd = input;
			}
			
			if ((cmd == "lef") || (cmd == "left")) {
				cmd = "";
				for (int i = 0; i < times; i++) {
					quadris->moveLeft();							
				}	
				quadris->display();	
				if (!notGUI) {
					drawGUI(quadris, &w);
				}
			} else if ((cmd == "ri") || (cmd == "rig") || (cmd =="righ") || (cmd == "right")) {	
				for (int i = 0; i < times; i++) {
					quadris->moveRight();				
				}
				quadris->display();
				if (!notGUI) {
					drawGUI(quadris, &w);
				}	
			} else if ((cmd == "do") || (cmd == "dow") || (cmd == "down")) {
				for (int i = 0; i < times; i++) {
					quadris->moveDown();				
				}
				quadris->display();
				if (!notGUI) {
					drawGUI(quadris, &w);
				}	
			} else if ((cmd == "cl") || (cmd == "clo") || (cmd == "cloc") || (cmd == "clock") || (cmd == "clockw") || (cmd == "clockwi") || (cmd == "clockwis") ||(cmd == "clockwise")) {
				for (int i = 0; i < times; i++) {
					quadris->rotate(1);					
				}
				quadris->display();
				if (!notGUI) {
					drawGUI(quadris, &w);
				}
			} else if ((cmd == "co") || (cmd == "cou") || (cmd == "coun") || (cmd == "count") || (cmd == "counte") || (cmd == "counter") || (cmd == "counterc") || (cmd == "countercl") || (cmd == "counterclo") || (cmd == "countercloc") || (cmd == "counterclock") || (cmd == "counterclockw") || (cmd == "counterclockwi") || (cmd == "counterclockwis") ||(cmd == "counterclockwise")) {
				for (int i = 0; i < times; i++) {
					quadris->rotate(-1);					
				}
				quadris->display();
				if (!notGUI) {
					drawGUI(quadris, &w);
				}
			} else if ((cmd == "dr") || (cmd == "dro") || (cmd == "drop")) {
				bool continueGame;
				for (int i = 0; i < times; i++) {				
					continueGame = quadris->drop();
					quadris->display();
					if (!notGUI) {
						drawGUI(quadris, &w);
					}
					if (!continueGame) {
						cout << "Game over!" << endl;
						break;
					}				
				}
				if (!continueGame) {
					break;
				}
			} else if ((cmd == "levelu") || (cmd == "levelup")) {
				for (int i = 0; i < times; i++) {
					quadris->incLevel();
					
				}
				quadris->display();
				if (!notGUI) {
					drawGUI(quadris, &w);
				}	
			} else if ((cmd == "leveld") || (cmd == "leveldo") || (cmd == "leveldow") || (cmd == "leveldown")) {
				for (int i = 0; i < times; i++) {
					quadris->decLevel();					
				}
				quadris->display();
				if (!notGUI) {
					drawGUI(quadris, &w);
				}
			} else if ((cmd == "r") || (cmd == "re") || (cmd == "res") || (cmd == "rest") || (cmd == "resta") || (cmd == "restar") || (cmd == "restart")) {
				quadris->restart();
				quadris->display();
				if (!notGUI) {
					drawGUI(quadris, &w);
				}	
			} else if ((cmd == "help")) {
				cout <<"-----------------------------" << endl << endl;
				cout <<"Welcome to Quadris! - Created by Enoch Lo and Vidur Kumar" << endl;
				cout <<"Here are a few commands that will help you out!" << endl;
				cout <<"left or lef - Moves a block left" << endl;
				cout <<"right or ri - Moves a block right" << endl;
				cout <<"down or do - Moves a block down" << endl;
				cout <<"You can preface these commands with 1-9 to move them more units!" << endl << endl;
				cout <<"drop or dr - Drops the block into the grid until it hits a block or the bottom!" << endl << endl;
				cout <<"clock or cl - Rotates a block counter clockwise" << endl;
				cout <<"counterclock or co - Rotates a block counter clockwise!" << endl << endl;
				cout <<"levelup or levelu - Moves onto the next level!" << endl;
				cout <<"leveldown or leveld - Moves back to the previous level!" << endl << endl;
				cout <<"restart or re - Restarts the game by clearing the board and the score!" << endl << endl;
				cout <<"-----------------------------" << endl << endl;
			}
		}
	} else {
		while (cin >> input) {
			/*if (quadris->checkLose()) {
				break;
			} */
				
			c = input[0];
			if ((c >= '0') && (c <= '9')) {
				times = c - '0';
				cmd = input.substr(1);
			} else {
				times = 1;
				cmd = input;
			}
			
			if ((cmd == "lef") || (cmd == "left")) {
				cmd = "";
				for (int i = 0; i < times; i++) {
					quadris->moveLeft();							
				}	
				quadris->display();
			} else if ((cmd == "ri") || (cmd == "rig") || (cmd =="righ") || (cmd == "right")) {	
				for (int i = 0; i < times; i++) {
					quadris->moveRight();				
				}
				quadris->display();
			} else if ((cmd == "do") || (cmd == "dow") || (cmd == "down")) {
				for (int i = 0; i < times; i++) {
					quadris->moveDown();				
				}
				quadris->display();
			} else if ((cmd == "cl") || (cmd == "clo") || (cmd == "cloc") || (cmd == "clock") || (cmd == "clockw") || (cmd == "clockwi") || (cmd == "clockwis") ||(cmd == "clockwise")) {
				for (int i = 0; i < times; i++) {
					quadris->rotate(1);					
				}
				quadris->display();
			} else if ((cmd == "co") || (cmd == "cou") || (cmd == "coun") || (cmd == "count") || (cmd == "counte") || (cmd == "counter") || (cmd == "counterc") || (cmd == "countercl") || (cmd == "counterclo") || (cmd == "countercloc") || (cmd == "counterclock") || (cmd == "counterclockw") || (cmd == "counterclockwi") || (cmd == "counterclockwis") ||(cmd == "counterclockwise")) {
				for (int i = 0; i < times; i++) {
					quadris->rotate(-1);					
				}
				quadris->display();
			} else if ((cmd == "dr") || (cmd == "dro") || (cmd == "drop")) {
				bool continueGame;
				for (int i = 0; i < times; i++) {				
					continueGame = quadris->drop();
					quadris->display();
					if (!continueGame) {
						cout << "Game over!" << endl;
						break;
					}				
				}
				if (!continueGame) {
					break;
				}
			} else if ((cmd == "levelu") || (cmd == "levelup")) {
				for (int i = 0; i < times; i++) {
					quadris->incLevel();
					
				}
				quadris->display();
			} else if ((cmd == "leveld") || (cmd == "leveldo") || (cmd == "leveldow") || (cmd == "leveldown")) {
				for (int i = 0; i < times; i++) {
					quadris->decLevel();					
				}
				quadris->display();
			} else if ((cmd == "r") || (cmd == "re") || (cmd == "res") || (cmd == "rest") || (cmd == "resta") || (cmd == "restar") || (cmd == "restart")) {
				quadris->restart();
				quadris->display();
			} else if ((cmd == "help")) {
				cout <<"-----------------------------" << endl << endl;
				cout <<"Welcome to Quadris! - Created by Enoch Lo and Vidur Kumar" << endl;
				cout <<"Here are a few commands that will help you out!" << endl;
				cout <<"left or lef - Moves a block left" << endl;
				cout <<"right or ri - Moves a block right" << endl;
				cout <<"down or do - Moves a block down" << endl;
				cout <<"You can preface these commands with 1-9 to move them more units!" << endl << endl;
				cout <<"drop or dr - Drops the block into the grid until it hits a block or the bottom!" << endl << endl;
				cout <<"clock or cl - Rotates a block counter clockwise" << endl;
				cout <<"counterclock or co - Rotates a block counter clockwise!" << endl << endl;
				cout <<"levelup or levelu - Moves onto the next level!" << endl;
				cout <<"leveldown or leveld - Moves back to the previous level!" << endl << endl;
				cout <<"restart or re - Restarts the game by clearing the board and the score!" << endl << endl;
				cout <<"-----------------------------" << endl << endl;
			}
		}
	}
	
	delete quadris;
}

		
			
			
			
