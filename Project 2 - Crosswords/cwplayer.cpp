#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <string>
#include <utility>
#include <fstream>
#include <cctype>
#include <ctime>
#include <algorithm>
#include "Board.h"
#include "Dictionary.h"
#include "Functions.h"
#include "Player.h"

using namespace std::chrono;	//used for counting the time that the user took to solve the puzzle



int main(){

	cout << "||-------Crosswords Solver-------||" << endl << endl;

	ifstream inDic;
	ifstream inBoard;
	string boardFilename;
	string dicFilename;
	Board fullBoard, playerBoard;							//fullBoard is the board that is loaded from the file, that is finished and has all the words;
															//playerBoard is a new board (empty in the beginning), and it is going to be the board where the player
															//is going to play, insert words, etc., and also the board that is going to be shown/printed.
	Dictionary dic;

	loadPuzzle(dicFilename, inDic, boardFilename, inBoard);	//the function returns the name of the dictionary (dicFilename), as well as an ifstream that has it open
															//(inDic), and it also returns the name of the board file (boardFilename), and an ifstream that has it
															//open (inBoard)


	fullBoard = Board(inBoard);
	playerBoard = Board(fullBoard.getVertical(), fullBoard.getHorizontal());			//empty board with the same dimensions as fullBoard
	dic = Dictionary(inDic);

	addBlackCells(fullBoard, playerBoard);



	string playerName;
	char confirm;

	do{

	cout << "Insert your player name ==>> ";
	getline(cin, playerName);

	cout << "Do you confirm? (y/Y to continue) ";
	cin >> confirm;
	cin.ignore(1000, '\n');  //clears additional chars

	confirm = toupper(confirm);
	cout << endl;

	}while(confirm != 'Y');

	Player p(playerName);


	cout << endl;
	playerBoard.print();

	map<string, string> vert_clues, hor_clues;

	cluesCreator(dic, fullBoard, vert_clues, hor_clues);		//creates the clues for the user

	cout << endl;
	showClues(vert_clues, hor_clues);			//shows the initial clues for the user
	cout << endl;

	string position, wordAnswer;
	bool validInput = true;

	bool validWord = true;
	bool validPosForWord = true;
	bool alreadyPlaced = true;
	bool rightLength = true;
	word insertedWord;




	 high_resolution_clock::time_point t1, t2; 		//t1 = time at the beggining of the puzzle  ;   t2 = time at the end of the puzzle
	 duration<double> time_elapsed;		// t2 - t1 = time that the user took to solve the puzzle;



	 t1 = high_resolution_clock::now();		//"starts" the timer


	do{
			do{
			cout << "Position (LCD; CTRL-Z/CTRL-D = STOP) --> ";

			cin >> position;

			validInput = checkIfValidPos(playerBoard, position);

			if(!validInput)
				cout << "Invalid position. Please try again." << endl;

			cin.ignore(1000, '\n');

			if(!validInput)
				continue;



					cout << "Word ( -  --> remove word;  ?  --> help): ";
					cin >> wordAnswer;
					cin.ignore(1000, '\n');

					if(wordAnswer == "-"){

						word wordToBeRemoved;
						validPosForWord = true;
						wordToBeRemoved = playerBoard.checkForWordBeginning((unsigned)position.at(1) - (unsigned)'a' + 1, (unsigned)position.at(0) - (unsigned)'A' + 1, position.at(2));

						if(wordToBeRemoved.wd == ""){			//returns an empty string if there is not a word that starts in that position

							cout << "There is no word that starts in that position! Try again." << endl;
							validPosForWord = false;

						}else{

							playerBoard.removeWord(wordToBeRemoved);
							addBlackCells(fullBoard, playerBoard);
							cout << endl;
							playerBoard.print();

							cout << endl;
							showClues(vert_clues, hor_clues);
							cout << endl;

						}

					}else if(wordAnswer == "?"){

						if(position.at(2) == 'V'){

							if(!changeClues(position, vert_clues, dic, fullBoard, p)){

								cout << endl << "No other synonyms to be shown for this word!" << endl;
							}

							cout << endl;
							playerBoard.print();

							cout << endl;
							showClues(vert_clues, hor_clues);
							cout << endl;



						}else{

							if(!changeClues(position, hor_clues, dic, fullBoard, p)){

							cout << endl << "No other synonyms to be shown for this word!" << endl;
							}

							cout << endl;
							playerBoard.print();

							cout << endl;
							showClues(vert_clues, hor_clues);
							cout << endl;


						}


			}else{

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

					word testWord;  //only to check if there is a word that starts in that position
					validPosForWord = true;
					testWord = fullBoard.checkForWordBeginning((unsigned)position.at(1) - (unsigned)'a' + 1, (unsigned)position.at(0) - (unsigned)'A' + 1, position.at(2));

				if(testWord.wd == ""){				//returns an empty string if there is not a word that starts in that position
					cout << "There is no word that starts in that position! Try again." << endl;
					validPosForWord = false;
				}

					alreadyPlaced = checkIfAlreadyPlaced(playerBoard, insertedWord);

					if(!alreadyPlaced){
						cout << "Word was already placed on the board! Please try again." << endl;
						continue;
					}

					rightLength = checkIfRightLength(fullBoard, insertedWord);

					if(!rightLength){
						cout << "Word doesn't have the right length! Please try again." << endl;
						continue;
					}


					}

			}while(!validWord || !validPosForWord || !alreadyPlaced || !validInput || !rightLength);


			if(wordAnswer != "-" && wordAnswer != "?"){

				//writes the word on the board (and blacks cells, in the right occasions)
				if(insertedWord.orientation == 1){

					playerBoard.addWordVertical(insertedWord.wd, insertedWord.initialX, insertedWord.initialY);
				} else playerBoard.addWordHorizontal(insertedWord.wd, insertedWord.initialX, insertedWord.initialY);


				cout << endl;
				playerBoard.print();

				cout << endl;
				showClues(vert_clues, hor_clues);
				cout << endl;

			}

			if(playerBoard.boardFull())
				cout << endl << "Board is completely full!" << endl;


		}while(!playerBoard.boardFull());

//when the board is full...
	cout << endl << "Doing a final check to see if all words are valid..." << endl;

	//if all the words are valid (belong to the dictionary)...
	if(finalWordCheck(dic, playerBoard))
		cout << endl << "All words are valid!" << endl;
	else cout << endl << "There are some words that do not belong to the dictionary. The board is not valid.";


//in the end, the playerBoard and the fullBoard from the beginning should be exactly equal, if the user solved the crosswords right
	if(boardsEqual(fullBoard, playerBoard)){

		t2 = high_resolution_clock::now();		//"stops" the timer

		time_elapsed = duration_cast<std::chrono::seconds>(t2 - t1);		//time_elapsed has now the amount of time (in seconds) that the user took to solve the
																		//crosswords puzzle

		cout << endl << "----->> CONGRATULATIONS!! You solved the puzzle correctly! <<-----" << endl;

		p.setFinalTime(time_elapsed);		//gives the player his final time

		cout << endl << "Writing your player profile in the board file..." << endl;




		string playerFile = boardFilename.substr(0, 4);
		playerFile = playerFile + "_p.txt";

		ofstream outPlayer(playerFile, ios::app);		//opens the player file in append mode so it can add to the end the player characteristics



		savePlayer(outPlayer, p);



		outPlayer.close();

		cout << endl << "Your player info was added to file " << playerFile << ". Thank you for playing! :-]\n";



	}else cout << endl << "You didn´t solve the puzzle correctly... Try again.";




	inDic.close();

	inBoard.close();


return 0;
}
