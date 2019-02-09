#include "Board.h"
#include "Functions.h"
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------
//returns the number of columns
int Board::getHorizontal() const{
	return hor_length;
}

//-------------------------------------------------------------------------------------------------------------------------
//returns the number of lines
int Board::getVertical() const{
	return vert_length;
}

//----------------------------------------------------------------------------------------------------------------------------
//default constructor, builds a 5x5 board

Board::Board() {
	int vertical = 5;
	int horizontal = 5;
	this->vert_length = vertical;
	this->hor_length = horizontal;
	this->total_hor_length = horizontal + 1;
	this->total_vert_length = vertical +1;

	string alphabet_min = "abcdefghijklmnopqrstuvwxyz";
	string alphabet_mai = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	vboard.resize(total_vert_length + 1);

	//sets all to points
	for (int i = 0; i <= vertical; i++) {
        vboard[i].resize(total_hor_length,'.');
    }

	//sets the letters
	for (int i = 0; i < total_vert_length; i++) {
		for (int j = 0; j <= total_hor_length; j++) {
			if (i == 0 && j == 0) {
				vboard[i][j] = '/';
			}
			else if ( i == 0) {
				vboard[i][j] = alphabet_min[j - 1];
			}
			else if (j == 0 ) {
				vboard[i][j] = alphabet_mai[i - 1];
			}

		}
	}

}
//----------------------------------------------------------------------------------------------------------------
//Constructs a board with the parameters
Board::Board(unsigned int vertical, unsigned int horizontal){
	this->vert_length = vertical;
	this->hor_length = horizontal;
	this->total_hor_length = horizontal + 1;
	this->total_vert_length = vertical + 1;

	string alphabet_min = "abcdefghijklmnopqrstuvwxyz";
	string alphabet_mai = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	vboard.resize(total_vert_length + 1);

	//sets all to points
	for (int i = 0; i <= vertical; i++) {
        vboard[i].resize(total_hor_length,'.');
    }

	//sets the letters
	for (int i = 0; i < total_vert_length; i++) {
		for (int j = 0; j <= total_hor_length; j++) {
			if (i == 0 && j == 0) {
				vboard[i][j] = '/';
			}
			else if ( i == 0) {
				vboard[i][j] = alphabet_min[j - 1];
			}
			else if (j == 0 ) {
				vboard[i][j] = alphabet_mai[i - 1];
			}

		}
	}


}

//-----------------------------------------------------------------------------------------------------------------------------
//shows a board on the screen
void Board::print() {
	int vert = vert_length;
	int hor = hor_length;

	for (int i = 0; i <= vert; i++) {
		for (int j = 0; j <= hor; j++) {
			if (i == 0 && j == hor) {
				cout << RED << vboard.at(i).at(j) << NO_COLOR << endl;
			}
			else if (i == 0 || j == 0) {
				cout << RED << vboard.at(i).at(j) << NO_COLOR << "  ";
			}
			else if ((vboard.at(i).at(j) == '#') && j == hor) {
				cout << BLACK_B << WHITE << vboard.at(i).at(j) << NO_COLOR << endl;
			}
			else if (vboard.at(i).at(j) == '#') {
				cout << BLACK_B << WHITE << vboard.at(i).at(j) << BLACK << WHITE_B << "  " << NO_COLOR;
			}
			else if (j == (hor)) {
				cout << BLACK << WHITE_B << vboard.at(i).at(j) << NO_COLOR << endl;
			}
			else {
				cout << BLACK <<  WHITE_B <<vboard.at(i).at(j) << "  " << NO_COLOR;
			}
		}
	}


}

//------------------------------------------------------------------------------------------------------------------------
//adds a word in the vertical with the starting coordinates
void Board::addWordVertical(string input_word, int initialX, int initialY) {
	word sword;
	sword.wd = input_word;
	sword.initialX = initialX;
	sword.initialY = initialY;
	sword.orientation = 1;

	int word_length = input_word.length();

	for (int i = 0; i < word_length; i++) {
		vboard[i + initialY][initialX] = input_word[i];
	}

	vwords.insert(sword);
	vwords_vert.insert(sword);
}


//----------------------------------------------------------------------------------------------------------------------------
void Board::addWordHorizontal(string input_word, int initialX, int initialY) {
	word sword;
	sword.wd = input_word;
	sword.initialX = initialX;
	sword.initialY = initialY;
	sword.orientation = 2;

	int word_length = input_word.length();
	for (int i = 0; i < word_length; i++) {
		vboard[initialY][i + initialX] = input_word[i];
	}

	vwords.insert(sword);
	vwords_hor.insert(sword);
}

//------------------------------------------------------------------------------------------------------------------------
//returns a vector of the words added to the board
set<word> Board::getWords() const{
	return this->vwords;
}

//-----------------------------------------------------------------------------------------------------------------------------
//prints all the words added to a board
void Board::printWords() {

	for(auto e : vwords)
		cout << e.wd << endl;

}

//-----------------------------------------------------------------------------------------------------------------------------------
//returns a vector of all the chars in a column
vector<char> Board::getColumn(int columnX) const{
	vector<char> col;

	for (int i = 1; i < total_vert_length; i++) {
		col.push_back(vboard[i][columnX]);
	}

	return col;
}

//------------------------------------------------------------------------------------------------------------------------------------
//prints all the chars in a column
void Board::printColumn(int columnX) {
	for (int i = 1; i < total_vert_length; i++) {
		cout << vboard[i][columnX] << " ";
	}

	cout << endl;
}

//---------------------------------------------------------------------------------------------------------------------------------------
//returns a vector of all the chars in a line
vector<char> Board::getLine(int lineY) const{
	vector<char> line;

	for (int i = 1; i < total_hor_length; i++) {
		line.push_back(vboard[lineY][i]);
	}

	return line;
}

//------------------------------------------------------------------------------------------------------------------------------------------
void Board::printLine(int lineY) {
	for (int i = 1; i < total_hor_length; i++) {
		cout << vboard[lineY][i] << " ";
	}

	cout << endl;
}

//--------------------------------------------------------------------------------------------------------------------------------------------
//adds a black cell with coordinates (coordX, coordY)
void Board::addBlackCell(int coordX, int coordY) {
	vboard[coordY][coordX] = '#';
}

//--------------------------------------------------------------------------------------------------------------------------------------------
//adds a '.' int the cell with coordinates (coordX, coordY)
void Board::addEmptyCell(int coordX, int coordY){

	vboard.at(coordY).at(coordX) = '.';
}


//-----------------------------------------------------------------------------------------------------------------------------------------
//return the cell in the given coordinates
char Board::getCell(int coordX, int coordY){

	return vboard.at(coordY).at(coordX);

}

//-----------------------------------------------------------------------------------------------------------------------------------------
//returns the whole board
vector<vector<char> > Board::getBoard() const{

	return this->vboard;
}

//-----------------------------------------------------------------------------------------------------------------------------------------
//returns a vector with all the vertical words

set<word> Board::getVerticalWords() const{

	return this->vwords_vert;
}

//-----------------------------------------------------------------------------------------------------------------------------------------
//returns a vector with all the horizontal words

set<word> Board::getHorizontalWords() const{

	return this->vwords_hor;
}

//-----------------------------------------------------------------------------------------------------------------------------------------
//true if the board is completely full with black cells and letters
bool Board::boardFull(){

	for(int i = 1; i < total_vert_length; i++){

		for(int j = 1; j < total_hor_length; j++){

			if(vboard.at(i).at(j) == '.')
				return false;

		}

	}

	return true;
}

//-----------------------------------------------------------------------------------------------------------------------------------------
//when a board finished and saved, all '.' chars need to be converted to '#' chars
void Board::fillBoard(){

	for(int i = 1; i < total_vert_length; i++){

		for(int j = 1; j < total_hor_length; j++){

			if(vboard.at(i).at(j) == '.')
				vboard.at(i).at(j) = '#';

		}

	}

}

//-----------------------------------------------------------------------------------------------------------------------------------------
//checks if all words in the board are valid (done at the end of user input)
bool finalWordCheck(const Dictionary &dic, const Board &board){

		vector<char> boardStrip;

		for(int i = 1; i < board.total_vert_length; i++){

			boardStrip = board.getLine(i);

			string testString;

			for(int j = 0; j < boardStrip.size(); j++){

				if(boardStrip.at(j) == '#' || j == boardStrip.size() - 1){

					if(j == boardStrip.size() - 1 && boardStrip.at(j) != '#')
						testString.push_back(boardStrip.at(j));

					if(testString.length() > 1){

					word createWord;
					createWord.wd = testString;

					if(!checkIfValidWord(createWord, dic))
						return false;
					}
					testString.clear();

				}else{
					testString.push_back(boardStrip.at(j));

				}


				}

			}

		for(int k = 1; k < board.total_hor_length; k++){

			boardStrip = board.getColumn(k);

			string testString;

			for(int j = 0; j < boardStrip.size(); j++){

				if(boardStrip.at(j) == '#' || j == boardStrip.size() - 1){

					if(j == boardStrip.size() - 1 && boardStrip.at(j) != '#')
						testString.push_back(boardStrip.at(j));

					if(testString.length() > 1){

						word createWord;
						createWord.wd = testString;

						if(!checkIfValidWord(createWord, dic))
							return false;
					}
						testString.clear();

						}else{
						testString.push_back(boardStrip.at(j));

						}


						}


		}



		return true;
		}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
//refills the board with all the words that are already there (used by removeWord, after remove the word, in order to replace mising letters)
void Board::refill(){

	for(auto insertedWord : vwords){

		if(insertedWord.orientation == 1){

						addWordVertical(insertedWord.wd, insertedWord.initialX, insertedWord.initialY);
					} else addWordHorizontal(insertedWord.wd, insertedWord.initialX, insertedWord.initialY);


					if(insertedWord.orientation == 1){

						if(insertedWord.initialY - 1 > 0)
							if(getCell(insertedWord.initialX, insertedWord.initialY - 1) == '.')
								addBlackCell(insertedWord.initialX , insertedWord.initialY - 1);

						if(insertedWord.wd.length() + insertedWord.initialY - 1 < getVertical())
							if(getCell(insertedWord.initialX, insertedWord.initialY + insertedWord.wd.length()) == '.')
								addBlackCell(insertedWord.initialX, insertedWord.initialY + insertedWord.wd.length());
					}else{

						if(insertedWord.initialX - 1 > 0)
							if(getCell(insertedWord.initialX - 1, insertedWord.initialY) == '.')
								addBlackCell(insertedWord.initialX - 1 , insertedWord.initialY);

						if(insertedWord.wd.length() + insertedWord.initialX - 1 < getHorizontal())
							if(getCell(insertedWord.initialX + insertedWord.wd.length(), insertedWord.initialY) == '.')
								addBlackCell(insertedWord.initialX + insertedWord.wd.length(), insertedWord.initialY);


					}

	}


}

void Board::removeElement(set<word> &set, word element){

	set.erase(set.find(element));

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//returns the word that starts in that position and has that orientation (empty string if there is no word)
word Board::checkForWordBeginning(int initialX, int initialY, char orientation){

	/*word finalWord;
	string finalString;
	vector<char> boardStrip;

	if(orientation == 'V'){

		boardStrip = getColumn(initialX);

		for(int i = initialY - 1; i < boardStrip.size(); i++){

			if(boardStrip.at(i) == '#')
				break;

		}

		finalWord.wd = finalString;
		finalWord.initialX = initialX;
		finalWord.initialY = initialY;
		finalWord.orientation = 1;
		return finalWord;

	}else{

		boardStrip = getLine(initialY);

		for(int j = initialX - 1; j < boardStrip.size(); j++){

			if(boardStrip.at(j) == '#')
				break;

		}

		finalWord.wd = finalString;
		finalWord.initialX = initialX;
		finalWord.initialY = initialY;
		finalWord.orientation = 2;
		return finalWord;

	}*/

	word finalWord;

	if(orientation == 'V'){

		for(auto e : vwords_vert){

			if(e.initialX == initialX && e.initialY == initialY){

				finalWord.wd = e.wd;
				finalWord.initialX = initialX;
				finalWord.initialY = initialY;
				finalWord.orientation = 1;
				return finalWord;
			}

		}

		finalWord.wd = "";
		return finalWord;

	}else{

		for(auto e : vwords_hor){

			if(e.initialX == initialX && e.initialY == initialY){

				finalWord.wd = e.wd;
				finalWord.initialX = initialX;
				finalWord.initialY = initialY;
				finalWord.orientation = 2;
				return finalWord;
			}

		}

		finalWord.wd = "";
		return finalWord;

	}




}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//needed for removeElement to function and work
bool operator==(const word &firstWord, const word &secondWord){

	return firstWord.wd == secondWord.wd;

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//needed for implementation of the sets
bool operator<(const word &firstWord, const word &secondWord){

	return firstWord.wd < secondWord.wd;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//removes a word from the board (uses the private refill method)
void Board::removeWord(word removedWord){

	word dotWord;
	string dotString;  //strings that has all dots (length equal to the length of the removed word)

	for(int i = 0; i < removedWord.wd.length(); i++){

		dotString.push_back('.');
	}

	dotWord.wd = dotString;
	dotWord.initialX = removedWord.initialX;
	dotWord.initialY = removedWord.initialY;


	if(removedWord.orientation == 1){

		dotWord.orientation = 1;

		addWordVertical(dotString, removedWord.initialX, removedWord.initialY);
		this->removeElement(vwords, dotWord);
		this->removeElement(vwords_vert, dotWord);



		if(removedWord.initialY > 1)
			addEmptyCell(removedWord.initialX, removedWord.initialY - 1);


		if(removedWord.wd.length() + removedWord.initialY - 1 < getVertical())
			addEmptyCell(removedWord.initialX, removedWord.initialY + removedWord.wd.length());

		this->removeElement(vwords, removedWord);
		this->removeElement(vwords_vert, removedWord);

	}else{

		dotWord.orientation = 2;

		addWordHorizontal(dotString, removedWord.initialX, removedWord.initialY);
		this->removeElement(vwords, dotWord);
		this->removeElement(vwords_hor, dotWord);


		if(removedWord.initialX > 1)
			addEmptyCell(removedWord.initialX - 1, removedWord.initialY);

		if(removedWord.wd.length() + removedWord.initialX - 1 < getHorizontal())
			addEmptyCell(removedWord.initialX + removedWord.wd.length(), removedWord.initialY);


		this->removeElement(vwords, removedWord);
		this->removeElement(vwords_hor, removedWord);
	}




	refill();

}

//-------------------------------------------------------------------------------------------------------------------------------------
//stores a board in the storage_file
void Board::save(string storage_file, string dicName) {
	ofstream sfile;
	sfile.open(storage_file);

	sfile << dicName << endl << endl;

	int vert = vert_length;
	int hor = hor_length;

	//prints the board to the file
	for (int i = 1; i <= vert; i++) {
		for (int j = 1; j <= hor; j++) {
			if (j == (hor)) {
				sfile << vboard[i][j] << endl;
			}
			else {
				sfile << vboard[i][j] << " ";
			}
		}
	}

	sfile << endl;

	for(auto e : vwords){

		string position;
		int i, j;
		j = e.initialY + (unsigned)'A' - 1;
		i = e.initialX + (unsigned)'a' - 1;
		position.push_back((char)j);
		position.push_back((char)i);

		if(e.orientation == 1)
			position.push_back('V');
		else position.push_back('H');


		sfile << position << " " << e.wd << endl;

	}

	//dimensions of the board
	/*sfile << "DIMENSIONS:" << endl;
	sfile << vert_length << " " << hor_length << endl << endl;

	//prints the words
	sfile << "WORDS:" << endl;
	for(auto e : vwords)
		sfile << e.wd << " " << e.initialX << " " << e.initialY << " " << e.orientation << endl;

	//prints the blackCells
	sfile << endl << "BLACK_CELLS:" <<endl;
	for (int i = 0; i < vbcells.size(); i++) {
		sfile << vbcells[i].initialX << " " << vbcells[i].initialY << endl;
	}*/

	sfile.close();

}


//----------------------------------------------------------------------------------------------------------------------------------------------
//resets a board and resizes it
void Board::resize(unsigned int vertical, unsigned int horizontal) {
	vboard.clear();

	this->vert_length = vertical;
	this->hor_length = horizontal;
	this->total_hor_length = horizontal + 1;
	this->total_vert_length = vertical +1;

	string alphabet_min = "abcdefghijklmnopqrstuvwxyz";
	string alphabet_mai = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	vboard.resize(total_vert_length + 1);

	//sets all to points
	for (int i = 0; i <= vertical; i++) {
        vboard[i].resize(total_hor_length,'.');
    }

	//sets the letters
	for (int i = 0; i < total_vert_length; i++) {
		for (int j = 0; j <= total_hor_length; j++) {
			if (i == 0 && j == 0) {
				vboard[i][j] = '/';
			}
			else if ( i == 0) {
				vboard[i][j] = alphabet_min[j - 1];
			}
			else if (j == 0 ) {
				vboard[i][j] = alphabet_mai[i - 1];
			}

		}
	}


}

//----------------------------------------------------------------------------------------------------------------------------------------------
//initializes the static variable boardFileName
string Board::boardFileName = "b001.txt";

//----------------------------------------------------------------------------------------------------------------------------------------------
//increments the board file name by 1 (ex: b001 to b002)
void Board::incBoardFileName(){

	ostringstream oss1, oss2;
	oss1 << boardFileName.substr(1, 3);

	int number = stoi(oss1.str(), nullptr, 10);

	number++;
	oss2 << number;
	string numString = oss2.str();

	if(number < 10)
		boardFileName = "b00" + numString + ".txt";
	else if(number < 100)
		boardFileName = "b0" + numString + ".txt";
	else boardFileName = "b" + numString + ".txt";

}

//----------------------------------------------------------------------------------------------------------------------------------------------
//shows the current file name for a board (ex: b001; b002; etc...)
void Board::showBoardFileName(){

	cout << boardFileName;

}


//----------------------------------------------------------------------------------------------------------------------------------------------
//returns the current board file name
string Board::returnBoardFileName(){

	return boardFileName;
}

void Board::nextBoardFileName(){

	ifstream in;

	in.open(boardFileName);

	while(!in.fail()){

		incBoardFileName();
		in.close();
		in.open(boardFileName);

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------
//it loads an already existent board, and returns the board to the main function,
//as well as the dictionary filename, the ifstream that as acess to the
//dictionary file and the string that contains the name of the board file
Board::Board(ifstream &inBoard){


			string line;


			getline(inBoard, line);					//gets rid of the empty line between the dic name and the beginning of the board
			getline(inBoard, line);					//gets the first row of the board


			while(line != ""){

				istringstream iss(line);
				char cell;
				vector<char> lineVector;

				while(iss >> cell){

					lineVector.push_back(cell);

				}

				vboard.push_back(lineVector);


				getline(inBoard, line);
			}

			vert_length = vboard.size();
			hor_length = vboard.at(0).size();

			total_hor_length = hor_length + 1;
			total_vert_length = vert_length + 1;

			char firstLetterHor = 'a';
			char firstLetterVert = 'A';
			vector<char> firstLine;
			firstLine.push_back('/');

			for(int j = 0; j < vert_length; j++){

				firstLetterVert = (char)((unsigned)'A' + j);
				vboard.at(j).insert(vboard.at(j).begin(), firstLetterVert);

			}



			for(int i = 0; i < hor_length; i++){

				firstLetterHor = (char)((unsigned)'a' + i);
				firstLine.push_back(firstLetterHor);

			}

			vboard.insert(vboard.begin(), firstLine);



			while(getline(inBoard, line)){

				word wordOfThatLine;
				string holder;
				istringstream iss2(line);
				iss2 >> holder;

				wordOfThatLine.initialX = (unsigned)holder.at(1) - (unsigned)'a' + 1;
				wordOfThatLine.initialY = (unsigned)holder.at(0) - (unsigned)'A' + 1;
				if(holder.at(2) == 'V')
					wordOfThatLine.orientation = 1;
				else wordOfThatLine.orientation = 2;

				iss2 >> holder;
				wordOfThatLine.wd = holder;

				vwords.insert(wordOfThatLine);

				if(wordOfThatLine.orientation == 1)
					vwords_vert.insert(wordOfThatLine);
				else vwords_hor.insert(wordOfThatLine);


			}


}

//----------------------------------------------------------------------------------------------------------------------------------------------
//adds the black cells in fullBoard to the playerBoard
void addBlackCells(const Board &fullBoard, Board &playerBoard){

	for(int i = 1; i < fullBoard.total_vert_length; i++){

			for(int j = 1; j < fullBoard.total_hor_length; j++){

				if(fullBoard.vboard.at(i).at(j) == '#')
					playerBoard.vboard.at(i).at(j) = '#';


			}


	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------
//checks if two boards are equal (used to check if the user solved the crosswords correctly
bool boardsEqual(const Board &board1, const Board &board2){

		for(int i = 1; i < board1.total_vert_length; i++){

				for(int j = 1; j < board1.total_hor_length; j++){


					if(board1.vboard.at(i).at(j) != board2.vboard.at(i).at(j))
						return false;

				}


		}


		return true;
}
