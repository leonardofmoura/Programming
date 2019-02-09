#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


#include "Functions.h"
using namespace std;


//shows the user a set of instructions to the game
void instructions(){

cout << "--------------------INSTRUCTIONS--------------------" << endl;
cout << "In order to create the puzzle, you will be asked to input the name of the file" << endl;
cout << "where the dictionary is stored." << endl << endl;
cout << "After that you can choose the size of the board (lines and columns)." << endl << endl;
cout << "To put a word in the board,  you must first choose the position that its"  << endl;
cout << "first letter is going to ocuppy." << endl <<endl;
cout << "Example:" << endl;
cout << "Position: LCD  ---->  L- line;  C-column;  D-direction ( V for vertical, H for horizontal)" << endl << endl;
cout << "Or, if you wish to end the input, type in CTRL+Z (CTRL+D on Linux). If so, you will then be asked if" << endl;
cout << "you wish to save the puzzle in a text file for later use." << endl << endl;
cout << "If you choose to proceed, you will be asked to input a word. Alternatively, you can input:" << endl;
cout << "-   --> to remove the word in those coordinates" << endl;
cout << "?   --> to receive a list of words that can go in those coordinates" << endl << endl;
cout << "That is all for now. Enjoy!";


}

//the functions returns, by reference, the information that we need to know about the puzzle: the filename
//of the dictionary, the number of lines and columns of the board (addictional parameter is "in", in order
//to open the dictionary file
void createPuzzle(string &filename, int &lines, int &columns, ifstream& in){

			cout << "|---------------------------------------|" << endl;
			cout << "|                                       |" << endl;
			cout << "|     -----   CREATE PUZZLE   -----     |" << endl;
			cout << "|                                       |" << endl;
			cout << "|---------------------------------------|" << endl;

			bool valid;

			do{
				do {
					cout << "Dictionary File Name: ";
					cin >> filename;

					if (cin.fail()) {
						cout << "Invalid input, try again" << endl;
					}
					cin.clear();
					cin.ignore(1000,'\n');

				} while (cin.fail());

				in.open(filename);

				if(in.fail()){
					cout << "File non existent... please insert another file name" << endl;
				}

			} while(in.fail());


			cout << endl;
			cout << "Size of the Board:" << endl;
			do{
				cout << "Lines (5-20): ";
				cin >> lines;
				valid = true;

				if(cin.fail() || (lines < 5 || lines > 20)){

					cout << "Invalid input...please try again" << endl;
					valid = false;
					cin.clear();
					cin.ignore(1000, '\n');
				}else cin.ignore(1000, '\n');        			//clears any addicional chars

			}while(!valid);

			do{
				cout << "Columns (5-20): ";
				cin >> columns;
				valid = true;

				if(cin.fail() || (columns < 5 || columns > 20)){

					cout << "Invalid input...please try again" << endl;
					valid = false;
					cin.clear();
					cin.ignore(1000, '\n');
				}else cin.ignore(1000, '\n');        			//clears any additional chars

			}while(!valid);




}

void loadPuzzle(string &filename, ifstream &in, string &boardFilename, ifstream &inBoard){

	cout << "|---------------------------------------|" << endl;
	cout << "|                                       |" << endl;
	cout << "|     -----    LOAD PUZZLE    -----     |" << endl;
	cout << "|                                       |" << endl;
	cout << "|---------------------------------------|" << endl;


				do{
				cout << "Insert the name of the file in which the board is stored: ";

				do {
					cin >> boardFilename;

					if (cin.fail()) {
						cout << "Invalid input, try again..." << endl;
						cin.clear();
						cin.ignore(1000,'\n');
					}

				} while (cin.fail());

				inBoard.open(boardFilename);

				if(inBoard.fail())
					cout << "\nFile non existent... please insert another file name" << endl;

				cin.ignore(1000, '\n');    				   //clears any additional chars

				}while(inBoard.fail());

				getline(inBoard, filename);				//gets the name of the dictionary used to build that board
														//(the file name for the dictionary is in the first line of the board file)

				in.open(filename);





}
//it loads an already existent board, and returns the board to the main function,
//as well as the dictionary filename, the ifstream that as acess to the
//dictionary file and the string that contains the name of the board file

//checks if input is valid, and if its within the range of the dimensions of the board
bool checkIfValidPos(const Board &board, const string &position){

	if(position.length() != 3)										//if position doesnt have 3 chars, its invalid
		return false;
	else if(position.at(0) < 'A' || position.at(0) > 'T')				//'T', because max size of the board is 20
		return false;
	else if(position.at(1) < 'a' || position.at(1) > 't')				//'t', because max size of the board is 20
		return false;
	else if(position.at(2) != 'H' && position.at(2) != 'V')			//orientation must be horizontal or vertical
		return false;

	int vert_pos, hor_pos;

	vert_pos = (unsigned)position.at(0) - (unsigned)'A' + 1 ;			//gets the number (starting in 1) for the line and column of the board
	hor_pos = (unsigned)position.at(1) - (unsigned)'a' + 1;		    //in which we want to start inserting the word

	if(vert_pos > board.getVertical())
		return false;

	if(hor_pos > board.getHorizontal())
		return false;


	return true;

}

bool checkIfValidWord(const word &insertedWord, const Dictionary &dic){

	bool wordExistsInDic = false;

	for(auto e : dic.getDic()){

		if(insertedWord.wd == e.first){
			wordExistsInDic = true;
			break;
		}
	}

	if(!wordExistsInDic)						//returns false if the word does not belong in the dictionary
		return false;


	return true;
}

bool checkIfAlreadyPlaced(const Board &board, const word &insertedWord){

	if(!board.getWords().empty()){

		for(auto f: board.getWords()){									//if the word was already placed on the board,
																		//it returns false
			if(insertedWord.wd == f.wd)
				return false;

		}

	}
	return true;
}


bool checkIfValidPosForWord(const Board &board, const word &insertedWord){

	int boardLengthFromStartPos;

		if(insertedWord.orientation == 1){

			boardLengthFromStartPos = board.getVertical() - insertedWord.initialY + 1;
		}
		else boardLengthFromStartPos = board.getHorizontal() - insertedWord.initialX + 1;

		if(insertedWord.wd.length() > boardLengthFromStartPos){
																		//if the word does not fit in the board, given the
			return false;												//starting position of the word
		}

		vector<char> boardStrip;

		if(insertedWord.orientation == 1)
			boardStrip = board.getColumn(insertedWord.initialX);
		else boardStrip = board.getLine(insertedWord.initialY);

		if(insertedWord.orientation == 1){

		for(int i = 0; i < insertedWord.wd.length(); i++){

			if(insertedWord.wd.at(i) != boardStrip.at(insertedWord.initialY - 1 + i))
				if(boardStrip.at(insertedWord.initialY - 1 + i) != '.'){
					return false;
				}
		}

		}
		else {

			for(int j = 0; j < insertedWord.wd.length(); j++){

				if(insertedWord.wd.at(j) != boardStrip.at(insertedWord.initialX - 1 + j))
					if(boardStrip.at(insertedWord.initialX - 1 + j) != '.'){
						return false;
					}
			}



		}



		if(insertedWord.orientation == 1){

			if(insertedWord.initialY > 1){

				if(boardStrip.at(insertedWord.initialY - 2) != '.' && boardStrip.at(insertedWord.initialY - 2) != '#'){
					return false;	}
			}

			if(insertedWord.wd.length() + insertedWord.initialY - 1 < board.getVertical()){

				if(boardStrip.at(insertedWord.initialY + insertedWord.wd.length() - 1) != '.' && boardStrip.at(insertedWord.initialY + insertedWord.wd.length() - 1) != '#'){
					return false;	}			//not enough space for the black cell at the end of the word

			}

		}else{

			if(insertedWord.initialX > 1){

				if(boardStrip.at(insertedWord.initialX - 2) != '.' && boardStrip.at(insertedWord.initialX - 2) != '#'){
					return false;}				//not enough space for the black cell at the beginning of the word
				}

			if(insertedWord.wd.length() + insertedWord.initialX - 1 < board.getHorizontal()){

				if(boardStrip.at(insertedWord.initialX + insertedWord.wd.length() - 1) != '.' && boardStrip.at(insertedWord.initialX + insertedWord.wd.length() - 1) != '#'){
					return false;	}			//not enough space for the black cell at the end of the word

			}




		}




		return true;


}


void print_sugestions(string position, Board& board, Dictionary& dic) {
	vector<string> validWords;

	for (auto e : dic.getDic()) {
		word currentWord;

		currentWord.initialX = (unsigned)position.at(1) - (unsigned)'a' + 1;	    //indexes for the line and column of the
		currentWord.initialY = (unsigned)position.at(0) - (unsigned)'A' + 1;     //first letter of the inserted word

		if(position.at(2) == 'V')
			currentWord.orientation = 1;
		else {
			currentWord.orientation = 2;
		}

		currentWord.wd = e.first;

		if (checkIfValidPosForWord(board, currentWord) && checkIfAlreadyPlaced(board, currentWord)) {
			validWords.push_back(currentWord.wd);
		}
	}

	int wordNumber = validWords.size();

	if (wordNumber > 100) {
			print_lots_of_words(validWords);
	}
	else {
		for (int i = 0; i < validWords.size(); i++) {
			cout << validWords[i] << "; ";
		}
		cout << endl;
	}
	
}

void print_lots_of_words(vector<string>& validWords) {
	
	string ans;
	do {
	cout << "\nThere are more than 100 valid words, show all? (Y/N)\n";
	cout << "[N will print only the first 100 words] --> ";

	
		cin >> ans;
		if (cin.fail()) {
			cout << "Invalid Input try again\n";
			cin.clear();
			cin.ignore(1000,'\n');

		}

		else if (ans == "Y" || ans == "y") {
			for (int i = 0; i < validWords.size(); i++) {
				cout << validWords[i] << "; ";
			}
		}
		else if (ans == "N" || ans == "n") {
			for (int i = 0; i <= 100 ; i++) {
				cout << validWords[i] << "; ";
			}
		}
		else {
			cout << "Invalid Input try again\n";
		}
	} while(ans != "Y" && ans != "y" && ans != "N" && ans != "n");
	cout << endl;
}

void cluesCreator(const Dictionary &dic, const Board &board, map<string, string> &vert_clues, map<string, string> &hor_clues){

	map<string, vector<string> > dictionary;
	dictionary = dic.getDic();

	set<word> vert_words = board.getVerticalWords();
	set<word> hor_words = board.getHorizontalWords();

	srand((unsigned int) time(NULL));

	for(auto e : vert_words){

		vector<string> wordSynonyms;
		string position, synonym;
		position.push_back((char)(e.initialY + (unsigned)'A' - 1));				//gets the position/coordinates of that word
		position.push_back((char)(e.initialX + (unsigned)'a' - 1));				//in "letter format"


		wordSynonyms = dictionary[e.wd];							//gets the vector of synonyms for that word

		int length = wordSynonyms.size();

		synonym = wordSynonyms.at(rand() % length);			//chooses a random synonym from the synonyms vector


		vert_clues.insert(pair<string, string>(position, synonym));


	}

	for(auto e : hor_words){

		vector<string> wordSynonyms;
		string position, synonym;
		position.push_back((char)(e.initialY + (unsigned)'A' - 1));				//gets the position/coordinates of that word
		position.push_back((char)(e.initialX + (unsigned)'a' - 1));				//in "letter format"


		wordSynonyms = dictionary[e.wd];						//gets the vector of synonyms for that word

		int length = wordSynonyms.size();

		synonym = wordSynonyms.at(rand() % length);			//chooses a random synonym from the synonyms vector

		hor_clues.insert(pair<string, string>(position, synonym));

	}



}


//shows the clues to the user
void showClues(const map<string, string> &vert_clues, const map<string, string> &hor_clues){

	cout << "VERTICAL:" << endl << endl;

	for(auto e : vert_clues){

		cout << e.first << "  " << e.second << endl;

	}

	cout << endl;

	cout << "HORIZONTAL:" << endl << endl;

	for(auto f : hor_clues){

		cout << f.first << "  " << f.second << endl;

	}

	cout << endl;


}


bool changeClues(const string &position, map<string, string> &clues, const Dictionary &dic, Board &board, Player &p){

		string pos = position.substr(0, 2);		//gets rid of the 'V'

		word wordInThatPos = board.checkForWordBeginning((unsigned)position.at(1) - (unsigned)'a' + 1, (unsigned)position.at(0) - (unsigned)'A' + 1, position.at(2));

			if(wordInThatPos.wd == ""){

				cout << "There is no word that starts in that position! Try again." << endl;
				return true;
			}


		string oldSynonym = clues[pos];
		string newSynonym;		//new synonym that is going to be generated and shown to the user, instead of the old synonym


		vector<string> synonymVector = dic.getDic()[wordInThatPos.wd];

		if(synonymVector.size() == 1)
			return false;   				//there is no other synonym to be shown

		srand((unsigned int) time(NULL));

		int length = synonymVector.size();

		do{

			newSynonym = synonymVector.at(rand() % length);		//randomly picks out another synonym from the synonym vector


		}while(oldSynonym == newSynonym); //just to make sure the randomly picked new synonym isn´t the same as the old synonym

		//in order to change the synonyms in the actual clues map...
		for(auto &e : clues){

			if(e.first == pos)
				e.second = newSynonym;

		}

		p.incAltClues(); //increments by 1 the number of alternative clues asked

		return true;

	}




void savePlayer(ofstream &outBoard, Player &p){

	outBoard << "Player " << p.getPlayerName() << " completed the puzzle in " << p.getTime().count() << " seconds, having asked for " << p.getAltClues() << " alternative clue(s)!";

	outBoard << endl;

}

bool checkIfRightLength(const Board &board, const word &insertedWord){

	for(auto e : board.getWords()){

		if(e.initialX == insertedWord.initialX && e.initialY == insertedWord.initialY)
			if(e.wd.length() != insertedWord.wd.length())
				return false;

	}

	return true;
}
