#include "block.h"
#include <iostream>

using namespace std;

Block::Block() {}

Block::~Block() {}


bool Block::notify(int *score, int nx, int ny) {
	for (int i = 0; i < 4; i++) {
		if ((allCells[i].x == nx) && (allCells[i].y == ny)) {
			allCells[i].x = -1;
			allCells[i].y = -1;
		}
	}
	totalCellsLeft -= 1;
	if (totalCellsLeft == 0) {
		*score += (level + 1) * (level + 1);
		return true;	
	} else {
		return false;
	}
}

void Block::notifyDisplay(TextDisplay &td, int x, int y) {
	/*int x;
	int y;
	for (int i = 0; i < 4; i++) {
		x = (allCells[i]).x;
		y = (allCells[i]).y;
		if ((x != -1) && (y != -1)) {
			td.notify(x, y, typeBlock);
		}
	} */
	
	td.notify(x, y, typeBlock);
}
int Block::getRotation() {
	return pos;
}

void Block::RotateClock() {
	if (pos == 4) {
		pos = 1;
		}
	else {
		pos++;
	}
}

void Block::RotateCountClock() {
	if (pos == 1) {
		pos = 4;
	}
	else {
		pos--;
	}
}

char Block::getTypeBlock() {
	return typeBlock;
}

void Block::setBlockPos(int x, int y) {
	BlockX = x;
	BlockY = y;
}

BlockPos *Block::getBlockPos() {
	return allCells;
}

int Block::getLevel() {
	return level;
}

void Block::incLevel () {
	level++;
}

void Block::decLevel() {
	level--;
}

int Block::returnCellsLeft() {
	return totalCellsLeft; 
}

void Block::moveLeft() {
	BlockY -= 1;
	
}

void Block::moveRight() {
	BlockY += 1;
}

void Block::moveDown() {
	BlockX += 1;
}
