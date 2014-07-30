#include "lblock.h"
#include <iostream>

using namespace std;

LBlock::LBlock(int level) {
	typeBlock = 'L';
	pos = 1;
	BlockX=0;
	BlockY=2;
	this->level = level;
	totalCellsLeft = 4;
	this->allPos();	
}

void LBlock::allPos() {

	int currentX = BlockX;
	int currentY= BlockY;

	if (pos == 1) {
		// 1st cell
		allCells [0].x = currentX;
		allCells [0].y = currentY; 
		//2nd cell
		allCells [1].x = currentX;
		allCells [1].y= currentY + 1;
		//3rd cell
		allCells [2].x = currentX + 1;
		allCells [2].y = currentY + 1;
		//4th cell
		allCells [3].x = currentX + 2;
		allCells [3].y = currentY + 1;
	}
	else if (pos == 2) {
		// 1st cell
		allCells [0].x = currentX;
		allCells [0].y = currentY - 1; 
		//2nd cell
		allCells [1].x = currentX + 1;
		allCells [1].y  = currentY - 1;
		//3rd cell
		allCells [2].x = currentX;
		allCells [2].y = currentY;
		//4th cell
		allCells [3].x = currentX;
		allCells [3].y = currentY + 1;
	}
	else if (pos == 3) {
		// 1st cell
		allCells [0].x = currentX;
		allCells [0].y = currentY; 
		//2nd cell
		allCells [1].x = currentX + 1;
		allCells [1].y= currentY;
		//3rd cell
		allCells [2].x = currentX +2;
		allCells [2].y = currentY;
		//4th cell
		allCells [3].x = currentX + 2;
		allCells [3].y = currentY + 1;
	}
	else {
		// 1st cell
		allCells [0].x = currentX + 1;
		allCells [0].y = currentY - 1; 
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
}
