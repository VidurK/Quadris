#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <sstream>


class TextDisplay {
	
	
	public:
	char **theDisplay;
	TextDisplay();
	~TextDisplay();
	
	void clearGrid();
	void notify(int r, int c, char ch);
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
