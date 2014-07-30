#ifndef GRID_H
#define GRID_H
#include <iostream>
#include "block.h"
#include "grid.h"
#include "textdisplay.h"

class Grid {
	//Block ***theGrid; // 2D array of Block Pointers
	
	
	
	
	
	public:
	TextDisplay *td;
	Block ***theGrid; // 2D array of Block Pointers
	Block *current;
	Block *next;
	Grid();
	~Grid();
	
	void removeDisplay(); // clear the location of current from theGrid
	void notifyDisplay(); // "pastes" the location of current onto theGrid
	
	void refresh(); // refreshes view
	
	bool lose();
	
	void clearGrid();
	bool checkMove(char dir); // check if the direction you want to move in is blocked
	void moveLeft(); // moves the moving block left
	void moveRight(); // moves the moving block right
	void moveDown(); // moves the moving block down
	void rotateClock(); // rotates the moving block clockwise
	void rotateCounterClock(); // rotates the moving block counterclockwise
	
	void setNext(Block *b); // sets the next block
	void setCurrent(); // turns next into current and adds it to the top left corner of grid
	void clearLine(int *score, int level); // checks to see if a line can be cleared, if so adds the points to *score
										 // in addition, if any blocks are fully cleared, it'll add that to the score as well
										 // ENOCH'S FXN
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
	
	bool checkClock();
	bool checkCountClock();
};

#endif

