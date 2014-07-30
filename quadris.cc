#include "quadris.h"
#include <cstdlib>
using namespace std;


Quadris::Quadris(int l, int s, string sc) {
	level = l;
	seed = s;
	script = sc;
	if (script == "") {
		script = "sequence.txt";
	}
	blocks.open(script.c_str());
	srand(seed);
	score = 0;
	highscore = 0;
	
	grid = new Grid();
	grid->setNext(getBlock());	
	grid->setCurrent();
	grid->setNext(getBlock());
}

Quadris::~Quadris() {
	blocks.close();
	delete grid;
}

void Quadris::clearLine() {
	grid->clearLine(&score, level);
	
}

Block *Quadris::getBlock() { 	
	int prob;

	if(level == 0) {
		string whichBlock;
		if (blocks >> whichBlock) {
			if ( whichBlock == "I") {
				IBlock *newBlock = new IBlock(level);
				return newBlock;
			}
			else if ( whichBlock == "J") {
				JBlock *newBlock = new JBlock(level);
				return newBlock;
			}
			else if ( whichBlock == "Z") {
				ZBlock *newBlock = new ZBlock(level);
				return newBlock;
			}
			else if ( whichBlock == "O") {
				OBlock *newBlock = new OBlock(level);
				return newBlock;
			}
			else if ( whichBlock == "L") {
				LBlock *newBlock = new LBlock(level);
				return newBlock;
			}
			else if ( whichBlock == "T") {
				TBlock *newBlock = new TBlock(level);
				return newBlock;
			}
			else if ( whichBlock == "S") {
				SBlock *newBlock = new SBlock(level);
				return newBlock;
			}
			else {
				return 0;
			}
		}
	}		
	else if (level == 1) {
		prob = rand() % 12;
		if ( prob == 0 || prob == 1) {
			IBlock *newBlock = new IBlock(level);
			return newBlock;
		}
		else if ( prob == 2 || prob == 3) {
			JBlock *newBlock = new JBlock(level);
			return newBlock;
		}
		else if ( prob == 4) {
			ZBlock *newBlock = new ZBlock(level);
			return newBlock;
		}
		else if ( prob == 5 || prob == 6) {
			OBlock *newBlock = new OBlock(level);
			return newBlock;
		}
		else if ( prob == 7 || prob == 8) {
			LBlock *newBlock = new LBlock(level);
			return newBlock;
		}
		else if ( prob == 9 || prob == 10) {
			TBlock *newBlock = new TBlock(level);
			return newBlock;
		}
		else if ( prob == 11) {
			SBlock *newBlock = new SBlock(level);
			return newBlock;
		}
	}
	else if (level == 2) {
		prob = rand() % 7;
		
		if ( prob == 0 ) {
			IBlock *newBlock = new IBlock(level);
			return newBlock;
		}
		else if ( prob == 1) {
			JBlock *newBlock = new JBlock(level);
			return newBlock;
		}
		else if ( prob == 2) {
			ZBlock *newBlock = new ZBlock(level);
			return newBlock;
		}
		else if ( prob == 3) {
			OBlock *newBlock = new OBlock(level);
			return newBlock;
		}
		else if ( prob == 4) {
			LBlock *newBlock = new LBlock(level);
			return newBlock;
		}
		else if ( prob == 5) {
			TBlock *newBlock = new TBlock(level);
			return newBlock;
		}
		else if ( prob == 6) {
			SBlock *newBlock = new SBlock(level);
			return newBlock;
		}
	}
	else if (level == 3) {
		prob = rand() % 9;
		
		if ( prob == 0 ) {
			IBlock *newBlock = new IBlock(level);
			return newBlock;
		}
		else if ( prob == 1) {
			JBlock *newBlock = new JBlock(level);
			return newBlock;
		}
		else if ( prob == 2 || prob == 3) {
			ZBlock *newBlock = new ZBlock(level);
			return newBlock;
		}
		else if ( prob == 4) {
			OBlock *newBlock = new OBlock(level);
			return newBlock;
		}
		else if ( prob == 5) {
			LBlock *newBlock = new LBlock(level);
			return newBlock;
		}
		else if ( prob == 6) {
			TBlock *newBlock = new TBlock(level);
			return newBlock;
		}
		else if ( prob == 7 || prob == 8) {
			SBlock *newBlock = new SBlock(level);
			return newBlock;
		}
	}
	return 0;
}

bool Quadris::moveLeft() {
	if (grid->checkMove('l')) {
		grid->moveLeft();	
		return true;
	}
	
	return false;
}

bool Quadris::moveRight() {
	if (grid->checkMove('r')) {
		grid->moveRight();
		return true;
	}
	
	return false;
}

bool Quadris::moveDown() {
	if (grid->checkMove('d')) {
		grid->moveDown();
		return true;
	}
	
	return false;
}

void Quadris::rotate(int dir) {
	if (dir == 1) {
		cout << "checking.." << endl;
		if (grid->checkClock()) {
			cout << "rotating" << endl;
			grid->rotateClock();
		}
	} else {
		if (grid->checkCountClock()) {
			grid->rotateCounterClock();
		}
	}
}

bool Quadris::drop() {
	while (grid->checkMove('d')) {
		grid->moveDown();
	}
	
	grid->clearLine(&score, level);
	
	bool lose = grid->lose();
	
	if (lose) {
		cout << "lost" << endl;
		return false;
	}
	
	grid->setCurrent();
	Block *temp = getBlock();
	if (temp != 0) {
		grid->setNext(temp);
	}
	else {
		grid->setNext(0);
	}
	
	grid->refresh();
	
	return true;
	
			
}

void Quadris::incLevel() {
	if (level == 3) {
		return;
	} else {
		level++;
	}
}

void Quadris::decLevel() {
	if (level == 0) {
		return;
	} else {
		level--;
	}
}


void Quadris::restart() {
	score = 0;
	grid->clearGrid();
	
	grid->setNext(getBlock());
	grid->setCurrent();
	grid->setNext(getBlock());	
	grid->notifyDisplay();
	
	grid->refresh();
}

void Quadris::display() {
	if (score >= highscore) {
		highscore = score;
	}
	
	cout << "Level: " << level << endl;
	cout << "Score: " << score << endl;
	cout << "Highscore: " << highscore << endl;
	cout << "----------" << endl;
	
	cout << *grid << endl; // print grid

	cout << "----------" << endl;
	cout << "Next:" << endl;
	
	char nextBlock;
	if (grid->next != 0) {
		nextBlock = ((grid->next)->getTypeBlock());
	}
	else {
		nextBlock = '#';
	}

	if (nextBlock == 'J') {
		cout << "J" << endl;
		cout << "JJJ";
	}
	else if (nextBlock == 'I') {
		cout << "IIII";
	}
	else if (nextBlock == 'T') {
		cout << "TTT" << endl;
		cout << " T";
	}
	else if (nextBlock == 'S') {
		cout << " SS" << endl;
		cout << "SS";
	}
	else if (nextBlock == 'Z') {
		cout << "ZZ" << endl;
		cout << " ZZ";
	}
	else if (nextBlock == 'O') {
		cout << "OO" << endl;
		cout << "OO";
	}
	else if (nextBlock == 'L') {
		cout <<"  L" << endl;
		cout <<"LLL";
	}
	else if (nextBlock == '#') {
		cout << "End of the input file: Try out level 1, 2 or 3!";
	}
	cout << endl;
}


