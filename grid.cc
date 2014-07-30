#include "grid.h"
#include <iostream>

using namespace std;
Grid::Grid() {
	
	theGrid = new Block **[15];
	
	for (int i = 0; i < 15; i++) {
		theGrid[i] = new Block *[10];
	}
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			theGrid[i][j] = 0;
		}
	}
	
	current = 0;
	next = 0;
	
	td = new TextDisplay();
}

Grid::~Grid() {
	clearGrid();
	for (int i = 0; i < 15; i++) {
		delete [](theGrid[i]);
	}
	
	delete []theGrid;
	delete td;
}

void Grid::clearGrid() {
	int dummy = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			if (theGrid[i][j] != 0) {
				if (theGrid[i][j]->notify(&dummy, -1, -1)) {
					delete theGrid[i][j];
					theGrid[i][j] = 0;
				} else {
					theGrid[i][j] = 0;
				}				
			}
		}
	}
	delete next;
	next = 0;
}

void Grid::removeDisplay() {
	BlockPos *temp = current->getBlockPos();
	for (int i = 0; i < 4; i++) {
		if ((temp[i].x) != -1) {
			theGrid[(temp[i]).x][(temp[i]).y] = 0;
		}
	}
}
	
	
bool Grid::lose() { // returns true if you lose
	BlockPos *temp = next->getBlockPos();
	cout << (temp[0]).x << " " << (temp[0]).y << endl;
	cout << (temp[1]).x << " " << (temp[1]).y << endl;
	cout << (temp[2]).x << " " << (temp[2]).y << endl;
	cout << (temp[3]).x << " " << (temp[3]).y << endl;
	for (int i = 0; i < 4; i++) {
		if ((theGrid[(temp[i].x)][(temp[i].y)] != 0) && (theGrid[(temp[i].x)][(temp[i].y)] != next)) {
			cout << "exiting " << endl;
			return true;
		}
	}
	
	return false;
	
}
void Grid::notifyDisplay() {
	BlockPos *temp = current->getBlockPos();
	for (int i = 0; i < 4; i++) {
		if ((temp[i].x) != -1) {
			theGrid[(temp[i]).x][(temp[i]).y] = current;
		}
	}
}
void Grid::moveLeft(void) {
	removeDisplay();
	
	current->moveLeft();
	current->allPos();
	
	/* print
	BlockPos *temp = current->getBlockPos();
	cout << endl << "after" << endl;
	for (int i = 0; i < 4; i++) {
		cout << temp[i].x << " " << temp[i].y << endl;
	}
	done */
	
	notifyDisplay();
	td->clearGrid();
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			if (theGrid[i][j] != 0) {
				theGrid[i][j]->notifyDisplay(*td, i, j);
			}			
		}
	}
	
}

void Grid::moveRight(void) {
	removeDisplay();
	current->moveRight();
	current->allPos();
	notifyDisplay();
	td->clearGrid();
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			if (theGrid[i][j] != 0) {
				theGrid[i][j]->notifyDisplay(*td, i, j);
			}			
		}
	}
}

void Grid::moveDown(void) {
	removeDisplay();
	current->moveDown();
	current->allPos();
	notifyDisplay();
	td->clearGrid();
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			if (theGrid[i][j] != 0) {
				theGrid[i][j]->notifyDisplay(*td, i, j);
			}			
		}
	}
}

void Grid::refresh(void) {
	removeDisplay();
	current->allPos();
	notifyDisplay();
	td->clearGrid();
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			if (theGrid[i][j] != 0) {
				theGrid[i][j]->notifyDisplay(*td, i, j);
			}			
		}
	}
}


void Grid::rotateClock(void) {
	removeDisplay();
	current->RotateClock();
	current->allPos();
	notifyDisplay();
	td->clearGrid();
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			if (theGrid[i][j] != 0) {
				theGrid[i][j]->notifyDisplay(*td, i, j);
			}			
		}
	}
}

void Grid::rotateCounterClock(void) {
	removeDisplay();
	current->RotateCountClock();
	current->allPos();
	notifyDisplay();
	td->clearGrid();
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			if (theGrid[i][j] != 0) {
				theGrid[i][j]->notifyDisplay(*td, i, j);
			}			
		}
	}
}

void Grid::setNext(Block *b) {
	if(b!=0) next = b;
}

void Grid::setCurrent() {
	current = 0;
	if(next != 0) {
		current = next;
		BlockPos *temp = current->getBlockPos();

		notifyDisplay();
	
		td->clearGrid();
	
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 10; j++) {
				if (theGrid[i][j] != 0) {
					theGrid[i][j]->notifyDisplay(*td, i, j);
				}			
			}
		}
	}
}

bool Grid::checkClock(void) {
	//rotate it clockwise, and check if the new locations are out of bounds/has blocks there
	int original_pos = current->getRotation();
	current->RotateClock();
	current->allPos();
	BlockPos *temp = current->getBlockPos();
	
	for (int i = 0; i < 4; i++) {
		if ((temp[i].x < 0) || (temp[i].x > 14) || (temp[i].y < 0) || (temp[i].x > 9) ) {
			current->RotateCountClock();
			current->allPos();
			return false;
		}
		
		if (theGrid[(temp[i].x)][(temp[i].y)] != 0) {
			if (theGrid[(temp[i].x)][(temp[i].y)] != current) {
				current->RotateCountClock();
				current->allPos();
				return false;
			}
		}		
	}
	
	for (int i = 0; i < 4; i++) {
		cout << temp[i].x << " " << temp[i].y << endl;
	}
	
	current->RotateCountClock();
	current->allPos();
	return true;
	
	
}

bool Grid::checkCountClock(void) {
	//rotate it clockwise, and check if the new locations are out of bounds/has blocks there
	int original_pos = current->getRotation();
	current->RotateCountClock();
	current->allPos();
	
	BlockPos *temp = current->getBlockPos();
	
	for (int i = 0; i < 4; i++) {
		if ((temp[i].x < 0) || (temp[i].x > 14) || (temp[i].y < 0) || (temp[i].x > 9) ) {
			current->RotateClock();
			current->allPos();
			return false;
		}
		
		if (theGrid[(temp[i].x)][(temp[i].y)] != 0) {
			if (theGrid[(temp[i].x)][(temp[i].y)] != current) {
				current->RotateClock();
				current->allPos();
				return false;
			}
		}		
	}
	current->RotateClock();
	current->allPos();
	
	for (int i = 0; i < 4; i++) {
		cout << temp[i].x << " " << temp[i].y << endl;
	}
	return true;
	
	
}

bool Grid::checkMove(char dir) {
	BlockPos *temp = current->getBlockPos();
	if (dir == 'l') {
		for (int i = 0; i < 4; i++) {
			if ((temp[i]).y == 0) {
				return false;
			}
		}
		
		for (int i = 0; i < 4; i++) {
			if (theGrid[(temp[i].x)][(temp[i].y) - 1] != 0) {
				if (theGrid[(temp[i].x)][(temp[i].y) - 1] != current) { // maybe replcae current by checking if it's temp[1..4]'s x and y
					
					return false;
				}
			}
		}
		// for each piece, check if the piece to the left is not 0 or one of the (temp[i]) then false
		
		//check if there's a piece to the left
		
	} else if (dir == 'r') {
		for (int i = 0; i < 4; i++) {
			if ((temp[i]).y == 9) {
				return false;
			}
		}
		
		for (int i = 0; i < 4; i++) {
			if (theGrid[(temp[i].x)][(temp[i].y) + 1] != 0) {
				if (theGrid[(temp[i].x)][(temp[i].y) + 1] != current) { // maybe replcae current by checking if it's temp[1..4]'s x and y
					return false;
				}
			}
		}
		//check if there's a piece to the right
	} else { // bottom
		for (int i = 0; i < 4; i++) {
			if ((temp[i]).x == 14) {
				return false;
			}
		}
		
		for (int i = 0; i < 4; i++) {
			if (theGrid[(temp[i].x) + 1][(temp[i].y)] != 0) {
				if (theGrid[(temp[i].x) + 1][(temp[i].y)] != current) { // maybe replcae current by checking if it's temp[1..4]'s x and y
					return false;
				}
			}
		}
		
	}
	
	return true;
}		
	
void Grid::clearLine(int *score, int level) {
	int linesCleared = 0;
	bool full = true;
	bool blockDone;
	for (int i = 0; i < 15; i++) {
		full = true;

		for (int j = 0; j < 10; j++) {
			if (theGrid[i][j] == 0) {
				full = false;
			}
		}
		
		if (full) {
			int count = 0;
			linesCleared += 1;
			for (int j = 0; j < 10; j++) { // remove the full row
				blockDone = (theGrid[i][j])->notify(score, i, j); // check if the block is completely gone
				if (blockDone) {
					delete theGrid[i][j];
					theGrid[i][j] = 0;
					count += 1;
				} else {
					theGrid[i][j] = 0;
					count += 1;
				}
			}
			for (int k = i; k > 0; k--) { // move all upper rows down one
				
				for (int j = 0; j < 10; j++) {
					theGrid[k][j] = theGrid[k-1][j];
					theGrid[k-1][j] = 0;
				}
			}
				
			
		}
	}
	
	if (linesCleared != 0) {
		*score += (level + linesCleared) * (level + linesCleared);
	}
	
	td->clearGrid();
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			if (theGrid[i][j] != 0) {
				theGrid[i][j]->notifyDisplay(*td, i, j);
			}			
		}
	}
}

ostream &operator<<(ostream &out, const Grid &g) {
	out << *(g.td);
	
	return out;
}		
		

