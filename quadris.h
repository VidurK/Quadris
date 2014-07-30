#ifndef QUADRIS_H
#define QUADRIS_H
#include <fstream>
#include <iostream>

#include "textdisplay.h"
#include "grid.h"
#include "block.h"
#include "iblock.h"
#include "lblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

class Quadris {
	
	int seed;
	
	std::string script;
	std::ifstream blocks;
	
	
	
	void clearLine(); // ask grid to iterate through itself to clear any completely filled lines, returns points earned
						  // passes Grid's clearLine a pointer to the score
	Block *getBlock(); // gets a random block
	
	public:
	int level;
	int score;
	int highscore;
	Grid *grid;
	Quadris(int level, int seed, std::string script);
	~Quadris();
	
	bool moveLeft(); // tell grid to shift moving block left if possible (true) by calling checkMove() and then executing g->moveLeft()
	bool moveRight(); // tell grid to shift moving block left if possible (true) by calling checkMove() and then executing g->moveRight()
	bool moveDown(); // tell grid to shift moving block left if possible (true) by calling checkMove() and then executing g->moveDown()
	void rotate(int dir); // tell grid to rotate moving block (1 for clockwise, -1 for counterclockwise)
	bool drop(); // call moveDown() until it returns false
	
	void incLevel(); // increase level by 1 if possible
	void decLevel(); // decrease level by 1 if possible
	void restart(); // clear the grid
	void display(); // cout << the grid
	
};
#endif
	
	
	
	
	
