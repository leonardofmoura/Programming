#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <string>
#include <utility>
#include <fstream>
#include <cctype>
#include "Board.h"
#include "Dictionary.h"
#include "Functions.h"

using namespace std;

int main(){

	instructions();
	cout << endl;

	cout << "--------------------------------------------" << endl;
	cout << "Options:" << endl;
	cout << "1 - Create puzzle (start from scratch)" << endl;
	cout << "2 - Load/Resume puzzle" << endl;     								//TO DO
	cout << "0 - Exit" << endl;

	int option;
	bool validOption;

	do{
	cout << "Option: ";
	cin >> option;
	validOption = true;

	if(cin.fail() || (option != 0 && option != 1 && option != 2)){

		cout << "Invalid option. Please try again." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		validOption = false;
	}
	else cin.ignore(1000, '\n');


	}
	while(!validOption);


	int lines, columns;
	ifstream in;
	ifstream inBoard;
	string boardFilename;
	string filename;
	Board b;
	Dictionary dic;

	switch(option){

	case 0:
		cout << endl << "Thank you for playing!" << endl;						//ends the program
		exit(0);

	case 1:
		createPuzzle(filename, lines, columns, in);
		b = Board(lines, columns);
		dic = Dictionary(in);
		break;

	case 2:
		loadPuzzle(filename, in, boardFilename, inBoard);
		b = Board(inBoard);
		dic = Dictionary(in);
		break;

	}

	b.printWords();

	cout << endl;
	b.print();

	string position, wordAnswer;
	bool anotherInput = true;						//false if user wants to stop the input
	bool validInput = true;

	bool validWord = true;
	bool validPosForWord = true;
	bool alreadyPlaced = true;
	word insertedWord;
	int saveOption;

	do{
		do{
		cout << "Position (LCD; CTRL-Z/CTRL-D = STOP) --> ";

		cin >> position;

		if(position == "END" || position == "end" || cin.fail() ){			//ATENCAO! CIN.EOF NAO DA PARA FAZER CLEAR, POR ISSO USA SE ISTO
			cin.clear();
			cin.ignore(1000,'\n');
			anotherInput = false;
		}
		else validInput = checkIfValidPos(b, position);

		if(!validInput)
			cout << "Invalid position. Please try again." << endl;

		cin.ignore(1000, '\n');

		if(anotherInput && !validInput)
			continue;

		if(!anotherInput){
			//cin.clear();			//clears the error state made by the end of file of cin, caused by pressing ctrl-z/ctrl-d
			//cin.ignore(1000, EOF);
			break;											//only continues if the user does not type in ctrl-z/crtl-d
		}



				cout << "Word ( -  --> remove word;  ?  --> help): ";

				do {
					cin >> wordAnswer;
					//cin.ignore(1000, '\n');
					if (cin.fail()) {
						cout << "Invalid input, try again..." << endl;
						cin.clear();
						cin.ignore(1000,'\n');
					}
				} while(cin.fail());

				if(wordAnswer == "-"){

					word wordToBeRemoved;
					validPosForWord = true;
					wordToBeRemoved = b.checkForWordBeginning((unsigned)position.at(1) - (unsigned)'a' + 1, (unsigned)position.at(0) - (unsigned)'A' + 1, position.at(2));

					if(wordToBeRemoved.wd == ""){			//returns an empty string if there is not a word that starts in that position

						cout << "There is no word that starts in that position! Try again." << endl;
						validPosForWord = false;

					}else{

						b.removeWord(wordToBeRemoved);
						cout << endl;
						b.print();

					}

				}
				else if (wordAnswer == "?") {
					print_sugestions(position, b, dic);
				}
				else {

				for(int i = 0; i < wordAnswer.length(); i++)
					wordAnswer.at(i) = toupper(wordAnswer.at(i));

				insertedWord.wd = wordAnswer;
				insertedWord.initialX = (unsigned)position.at(1) - (unsigned)'a' + 1;	    //indexes for the line and column of the
				insertedWord.initialY = (unsigned)position.at(0) - (unsigned)'A' + 1;     //first letter of the inserted word
				if(position.at(2) == 'V')
					insertedWord.orientation = 1;
				else insertedWord.orientation = 2;


				validWord = checkIfValidWord(insertedWord, dic);

				if(!validWord){
					cout << "Invalid word. Please try again." << endl;
					continue;
				}

				validPosForWord = checkIfValidPosForWord(b, insertedWord);

				if(!validPosForWord){
					cout << "Word can´t be placed there! Please try again." << endl;
					continue;
				}


				alreadyPlaced = checkIfAlreadyPlaced(b, insertedWord);

				if(!alreadyPlaced){
					cout << "Word was already placed on the board! Please try again." << endl;
					continue;
				}

				}

		}while(!validWord || !validPosForWord || !alreadyPlaced || (anotherInput && !validInput));


		if(anotherInput && wordAnswer != "-"){

			//writes the word on the board (and blacks cells, in the right occasions)
			if(insertedWord.orientation == 1){

				b.addWordVertical(insertedWord.wd, insertedWord.initialX, insertedWord.initialY);
			} 
			else b.addWordHorizontal(insertedWord.wd, insertedWord.initialX, insertedWord.initialY);


			if(insertedWord.orientation == 1){

				if(insertedWord.initialY - 1 > 0)
					if(b.getCell(insertedWord.initialX, insertedWord.initialY - 1) == '.')
						b.addBlackCell(insertedWord.initialX , insertedWord.initialY - 1);

				if(insertedWord.wd.length() + insertedWord.initialY - 1 < b.getVertical())
					if(b.getCell(insertedWord.initialX, insertedWord.initialY + insertedWord.wd.length()) == '.')
						b.addBlackCell(insertedWord.initialX, insertedWord.initialY + insertedWord.wd.length());
			}
			else{

				if(insertedWord.initialX - 1 > 0)
					if(b.getCell(insertedWord.initialX - 1, insertedWord.initialY) == '.')
						b.addBlackCell(insertedWord.initialX - 1 , insertedWord.initialY);

				if(insertedWord.wd.length() + insertedWord.initialX - 1 < b.getHorizontal())
					if(b.getCell(insertedWord.initialX + insertedWord.wd.length(), insertedWord.initialY) == '.')
						b.addBlackCell(insertedWord.initialX + insertedWord.wd.length(), insertedWord.initialY);


			}

			cout << endl;
			b.print();


		}

		if(b.boardFull())
			cout << endl << "Board is completely full!" << endl;


	}while(anotherInput && !b.boardFull());

	if(b.boardFull()){

		if(option == 1){   //if the board was created from scratch (doenst have a file yet)

		cout << endl << "Doing a final check to see if all words are valid..." << endl;

		if(finalWordCheck(dic, b)){
			cout << endl << "All words are valid!" << endl << "Saving board..." << endl;
			b.nextBoardFileName();
			b.save(b.returnBoardFileName(), filename);
			cout << endl << "Board saved in file " << b.returnBoardFileName() << "." << endl;
		}
		else cout << endl << "There are some words that do not belong to the dictionary. The board is not valid.";

		}
		else {		//if the option chosen ate the beginning wasnt option 1

			cout << endl << "Doing a final check to see if all words are valid..." << endl;

			if(finalWordCheck(dic, b)){
				cout << endl << "All words are valid!" << endl << "Saving board..." << endl;
				b.save(boardFilename, filename);
				cout << endl << "Board saved in file " << boardFilename << "." << endl;
			}
			else cout << endl << "There are some words that do not belong to the dictionary. The board is not valid.";


		}


	}
	else{
		bool validSaveOption;
		cout << endl << endl << "Do you wish to..." << endl;
		cout << "1 -> save the puzzle to continue later" << endl;
		cout << "2 -> save this puzzle as a finished puzzle?" << endl << endl;
		do{
			validSaveOption = true;
			cout << "Option: ";
			cin >> saveOption;
			if(cin.fail() || (saveOption != 1 && saveOption != 2)){

				cout << "Invalid option. Please try again." << endl;
				validSaveOption = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}else cin.ignore(1000, '\n');


		}while(!validSaveOption);



	if(saveOption == 2){

	cout << endl << "Filling board..." << endl;
	b.fillBoard();


	cout << endl << "Doing a final check to see if all words are valid..." << endl;


	if(finalWordCheck(dic, b)){

		cout << endl << "All words are valid!" << endl << "Saving board..." << endl;

		if(option == 1){

		b.nextBoardFileName();
		b.save(b.returnBoardFileName(), filename);
		cout << "Board saved in file " << b.returnBoardFileName() << "." << endl;

		}else{

			b.save(boardFilename, filename);
			cout << "Board saved in file " << boardFilename << "." << endl;


		}
	}
	else cout << endl << "There are some words that do not belong to the dictionary. The board is not valid.";

	}
	else {

		cout << endl << "Saving board..." << endl;

		if(option == 1){

			b.nextBoardFileName();
			b.save(b.returnBoardFileName(), filename);
			cout << "Board saved in file " << b.returnBoardFileName() << "." << endl;

		}
		else{

			b.save(boardFilename, filename);
			cout << "Board saved in file " << boardFilename << "." << endl;

		}
	}
	}


		in.close();
		if(inBoard.is_open())
			inBoard.close();


		return 0;

}
