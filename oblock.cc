#include "oblock.h"
#include <iostream>

using namespace std;

OBlock::OBlock(int level) {
	typeBlock = 'O';
	pos = 1;
	BlockX=0;
	BlockY=2;
	this->level = level;
	totalCellsLeft = 4;	
	this->allPos();
}

void OBlock::allPos() {

	int currentX = BlockX;
	int currentY= BlockY;

	// 1st cell
	allCells [0].x = currentX;
	allCells [0].y = currentY; 
	//2nd cell
	allCells [1].x = currentX + 1;
	allCells [1].y= currentY;
	//3rd cell
	allCells [2].x = currentX;
	allCells [2].y = currentY + 1;
	//4th cell
	allCells [3].x = currentX + 1;
	allCells [3].y = currentY + 1;
}
