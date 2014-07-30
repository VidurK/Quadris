#include "grid.h"
#include "block.h"
#include "textdisplay.h"

#include <iostream>

using namespace std;

int const BUFFER = 3;
TextDisplay::TextDisplay() {

	theDisplay = new char*[18];
	
	for (int i=0; i<18;i++) {
		theDisplay[i] = new char[10];
	}
	
	for (int i=0; i<18;i++) {
		for (int j=0; j<10;j++) {
			theDisplay[i][j]=' ';
		}
	}
}

TextDisplay::~TextDisplay() {
	for (int i=0; i<18;i++) {
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
}

void TextDisplay::clearGrid() {
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 10; j++) {
			theDisplay[i][j] = ' ';
		}
	}
}
	
	

void TextDisplay::notify(int r, int c, char ch) {
	theDisplay[r + 3][c] = ch;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	int count = 0;
	for (int i=0; i<18; i++) {
		for (int j=0; j<10; j++) {
			out << (td.theDisplay)[i][j];
		}
		if (count != 17) {
			count++;
			out << endl;
		}
	}
	
	return out;
}
