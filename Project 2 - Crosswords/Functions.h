#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "Board.h"
#include "Dictionary.h"
#include "Player.h"
using namespace std;

void instructions();
void createPuzzle(string &filename, int &lines, int &columns, ifstream &in);
void loadPuzzle(string &filename, ifstream &in, string &boardFilename, ifstream &inBoard);
bool checkIfValidPos(const Board &board, const string &position);
bool checkIfValidWord(const word &insertedWord, const Dictionary &dic);
bool checkIfValidPosForWord(const Board &board, const word &insertedWord);
bool checkIfAlreadyPlaced(const Board &board, const word &insertedWord);
void print_sugestions(string position, Board& board, Dictionary& dic);  //prints the sugentions for a given position
void print_lots_of_words(vector<string>& validWords); //used when there are more than 100 valid word suggestions
void cluesCreator(const Dictionary &dic, const Board &board, map<string, string> &vert_clues, map<string, string> &hor_clues);
void showClues(const map<string, string> &vert_clues, const map<string, string> &hor_clues);
bool changeClues(const string &position, map<string, string> &clues, const Dictionary &dic, Board &board, Player &p);
void savePlayer(ofstream &outBoard, Player &p);
bool checkIfRightLength(const Board &board, const word &insertedWord);

#endif /* FUNCTIONS_H_ */
