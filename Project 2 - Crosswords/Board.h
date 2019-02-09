#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include "Dictionary.h"
#include "color.h"
using namespace std;

//defined has a class and not a struct so as to use an iterator for set<word>
struct word {
	string wd;
	int initialX;
	int initialY;
	int orientation;  //1 = vertical; 2 = horizontal
};

/*struct blackCell {
	int initialX;
	int initialY;
};*/

bool operator==(const word &firstWord, const word &secondWord); //needed for removeElement to function and work
bool operator<(const word &firstWord, const word &secondWord);  //needed for implementation of the sets

class Board{

	friend bool finalWordCheck(const Dictionary &dic, const Board &board); 	//checks if all words in the board are valid (done at the end of user input)
	friend void addBlackCells(const Board &fullBoard, Board &playerBoard);   //adds the black cells in fullBoard to the playerBoard
	friend bool boardsEqual(const Board &board1, const Board &board2);	//checks if two boards are equal (used to check if the user solved the crosswords correctly


public:
	Board(); //default constructor, builds a 5x5 board
	Board(unsigned int vertical, unsigned int horizontal); //constructor with parameters
	Board(ifstream &inBoard); //loads and creates a board based on a file
	void print(); //shows a board on the screen
	int getHorizontal() const; //returns the number of columns
	int getVertical() const; //returns the number of rows
	void addWordVertical(string word, int initialX, int initialY); //Adds a word to a board in vertical position
	void addWordHorizontal(string word, int initialX, int initialY); //ads a word to the board in horizontal position
	set<word> getWords() const; //returns a vector of the words added to the board
	void printWords(); //prints all the words added to a board
	vector<char> getColumn(int columnX) const; //returns a vector of all the chars in a column
	void printColumn(int columnX); //prints all the chars in a column
	vector<char> getLine(int lineY) const; //returns a vector of all the chars in a line
	void printLine(int lineY); //prints all the chars in a line
	void addBlackCell(int coordX, int coordY); //adds a black cell with coordinates (coordX, coordY)
	void addEmptyCell(int coordX, int coordY); //adds a '.' int the cell with coordinates (coordX, coordY)
	char getCell(int coordX, int coordY); //returns a cell of the board
	vector<vector <char> > getBoard() const; //returns the whole board
	set<word> getVerticalWords() const; //returns a vector with all the vertical words
	set<word> getHorizontalWords() const; //returns a vector with all the horizontal words
	bool boardFull(); //true if the board is completely full with black cells and letters
	void fillBoard(); //when a board finished and saved, all '.' chars need to be converted to '#' chars
	void removeWord(word removedWord); //removes a word from the board (using the private refill method)
	word checkForWordBeginning(int initialX, int initialY, char orientation); //returns the word that starts in that position and has that orientation (empty string if there is no word)
	void save(string storage_file, string dicName); //saves a board in the storage_file
	static void showBoardFileName(); //shows the current file name for a board (ex: b001; b002; etc...)
	static string returnBoardFileName(); //returns the current board file name
	static void nextBoardFileName(); //gets the next possible name file for a board

private:
	static string boardFileName;

	static void incBoardFileName(); //increments the board file name by 1 (ex: b001 to b002)
	void refill(); //refills the board with all the words that are already there (used by removeWord, after removing the word, in order to replace missing letters)
	void removeElement(set<word> &set, word element); //removes a specific element from a vector (used by removeWord)
	void resize(unsigned int vertical, unsigned int horizontal); //resets a board and resizes it;
	vector< vector<char> > vboard;
	set<word> vwords;
	set<word> vwords_vert;
	set<word> vwords_hor;
	//vector<blackCell> vbcells;
	unsigned int vert_length;
	unsigned int hor_length;
	unsigned int total_hor_length;
	unsigned int total_vert_length;

};

#endif /* BOARD_H_ */
