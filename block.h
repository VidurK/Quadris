#ifndef BLOCK_H
#define BLOCK_H
 
#include <iostream>
#include "textdisplay.h"
// UP =  1 RIGHT = 2 DOWN = 3 LEFT = 4
 
struct BlockPos {
       int x;
       int y;
};
 
class Block {
	protected: 
	int BlockX;
	int BlockY;
	char typeBlock;
	int level;
	int totalCellsLeft;
	int pos; // 1, 2, 3, 4
	BlockPos allCells[4];
 
	public:

	bool notify(int *score, int nx, int ny); // when this is called, it'll decrease totalCells left by 1, and 
	// if it's 0 it'll update score accordingly and return true (which will prompt grid to delete the block using the pointer)
	// it'll also render the block's pieces that are cleared to be defunct (-1)

	void notifyDisplay(TextDisplay &td, int x, int y);
	
	Block(); // constructor for a block
	virtual ~Block(); // destructor
	virtual void allPos() = 0; // must be created from each block.
	
	int getRotation();
	void RotateClock();
	void RotateCountClock();
	char getTypeBlock();
	void setBlockPos(int x, int y);
	BlockPos* getBlockPos();
	int getLevel();
	void incLevel();
	void decLevel();
	int returnCellsLeft();
	
	void moveLeft();
	void moveRight();
	void moveDown();
};
#endif
