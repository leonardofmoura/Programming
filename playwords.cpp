//============================================================================
// Name        : PROJ.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <ctime>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void func1(vector<string> wordVector);
void func2(vector<string> wordVector);
void func3(vector<string> wordVector);
void func4(vector<string> wordVector);
void func5(vector<string> wordVector);
bool wildcardMatch(const char *str, const char *strWild);

void playwords(ifstream& outputDic){

	vector<string> wordVector;
	string aux;
	int option;

	//creates a vector with all the selected words, with no duplicates
	while(getline(outputDic, aux)){

		wordVector.push_back(aux);
	}

	// makes you choose one of five options, each one leading to a game; if invalid option, makes you choose again
	cout << "============================================================================================================================================================\n";
	cout << "                                                                          PLAYORDS                                                                          \n";
	cout << "============================================================================================================================================================\n\n\n";

	cout << "CHOOSE A GAME: " << endl;
	cout << "-> To check if a user-entered word belongs to the word list, press 1." << endl;
	cout << "-> To guess a random word from the list, having all the letters of the word scrambled, press 2." << endl;
	cout << "-> To be asked a set of N letters and receive all the words in the dictionary that can be formed using the set or any subset of the letters, press 3." << endl;
	cout << "-> To be asked to build a valid word, in order to check if that word is part of a randomly chosen set of N letters, press 4." << endl;
	cout << "-> To write a word containing wildcard chars ('*' and '?'), in order to receive all the words in the dictionary that match that word, press 5." << endl;

	cout << "Option >>> ";
	cin >> option;

	while((cin.fail()) || (option < 1) || (option > 5)){

		cin.clear();
		cin.ignore(1000, '\n');

		cerr << "Invalid input... please press a number from 1 to 5" << endl;
		cout << "Option: ";
		cin >> option;

	}
	cin.ignore(1000, '\n'); //clear any additional chars


	switch(option){

	case 1:
		func1(wordVector);
		break;

	case 2:
		func2(wordVector);
		break;							//calls one function, depending on the user input above

	case 3:
		func3(wordVector);
		break;

	case 4:
		func4(wordVector);
		break;

	case 5:
		func5(wordVector);
		break;
	}

}


//FUNC1 -> the user enters a word, and the function tells the user if the word is a dicitionary headline
void func1(vector<string> wordVector){

	cout << endl << "You chose game number 1." << endl << endl;
	cout << "======================\n";
	cout << "== DICTIONARY CHECK ==\n";
	cout << "======================\n";

	bool wordExists = false;
	string word;
	cout << "Please enter a word, in order to check if it exists in the word list." << endl;
	cout << "Word: ";
	getline(cin, word);

	for(int j = 0; j < word.length(); j++)
		word.at(j) = toupper(word.at(j));

	for(size_t i = 0; i < wordVector.size(); i++){

		if(wordVector.at(i) == word){
			wordExists = true;
			break;
		}
	}
	if(wordExists)
		cout << word << " belongs in the word list." << endl;
	else cout << word << " does not belong in the word list."  << endl;
}




void func2(vector<string> wordVector){

	cout << endl << "You chose game number 2." << endl << endl;

	cout << "======================\n";
	cout << "==    WORD GUESS    ==\n";
	cout << "======================\n";

	srand((unsigned int) time(NULL)); //for generating random numbers

	int randomIndex = rand() % wordVector.size();
	string randomWord = wordVector.at(randomIndex);
	string randomScrambledWord = randomWord;
	string userString;  //string the user is going to use to write their guesses

	int randWordIndex;
	char temp;

	for(size_t i = 0; i < randomScrambledWord.length(); i++){

		randWordIndex = rand() % randomScrambledWord.length();

		temp = randomScrambledWord.at(i);
		randomScrambledWord.at(i) = randomScrambledWord.at(randWordIndex);
		randomScrambledWord.at(randWordIndex) = temp;
	}

	cout << "Scrambled word: " << randomScrambledWord << endl;

	int numTries = 3;	//number of tries the user as left
	do{

		cout << "Number of tries left: " << numTries << endl;
		cout << "Try to guess the word: ";
		getline(cin, userString);

		for(int j = 0; j < userString.length(); j++)
				userString.at(j) = toupper(userString.at(j));

		if(userString == randomWord){

			cout << "Congratulations! You are right!";
			break;
		}else {
			numTries--;
			if(numTries > 1){

			cout << "You are wrong... Try again!" << endl << endl;
			}
		}

	} while(numTries > 0);

	if(numTries == 0){
		cout << "You are out of tries... better luck next time!" << endl;
		cout << "The correct word was: " << randomWord << endl;

	}
}


void func3(vector<string> wordVector) {

	cout << endl << "You chose game number 3." << endl << endl;

	cout << "======================\n";
	cout << "==  DICTIONARY GET  ==\n";
	cout << "======================\n";

	string letterSet;
	string currentLetter;
	vector<string> finalWords;
	char currentLetter_char;
	int currentLetterNum = 1;

	cout << "Type a set of letters in the format (enter a letter then press enter, type \"DONE\" when you finish)" << endl;
	cout << "Letter " << currentLetterNum << ":";

	while (getline(cin,currentLetter)) {
		currentLetter_char = currentLetter[0];

		if (currentLetter == "DONE") {
			break;
		}
		else if (!isalpha(int (currentLetter_char))) {
			//cin.clear();
			//cin.ignore(1000, '\n');
			cerr << "ERROR:Invalid input\n";
			cout << "Letter " << currentLetterNum << ":";
			continue;
		}
		else {
			letterSet += currentLetter_char;
		}

		currentLetterNum += 1;
		cout << endl << "Letters: " << letterSet << endl;
		cout << "Letter " << currentLetterNum << ":";

	}

	for (int i = 0; i < letterSet.length(); i++) { //converts all letters to uppercase
		letterSet[i] = toupper(int (letterSet[i]));
	}

	sort(letterSet.begin(), letterSet.end()); //sorts the letters introduced by the user

	for (size_t i = 0; i < wordVector.size(); i++) {
		if (wordVector[i].length() == letterSet.length()) {
			string currentWord = wordVector[i];
			sort(currentWord.begin(), currentWord.end());

			if (currentWord == letterSet) {
				finalWords.push_back(wordVector[i]);
			}

			else continue;
		}
		else continue;
	}

	if (finalWords.size() != 0) {
		cout << "\n The word(s) with the letters " << letterSet << " is(are): \n";

		for (int i = 0; i < finalWords.size(); i++) {
			cout << finalWords[i] << endl;
		}
	}
	else {
		cout << "There are no words with the letters " << letterSet << " in the dicionary\n";
	}


}

void func4(vector<string> wordVector) {
	cout << "You chose game number 4." << endl << endl;

	cout << "======================\n";
	cout << "==    WORD BUILD    ==\n";
	cout << "======================\n";

	srand ((unsigned int) time(NULL));

	int wordLength = (rand() % 4) + 3; //randomly choose the number of letters
	string letterSet = "BANANA	";
	string userWord;
	bool wordInDictionary = false;
	bool validWord = false;


	while (!validWord) {
		letterSet = "";
		for (int i = 0; i < wordLength; i++) {  //choses the set of letters
			char letter = char ((rand() % 25) + 65);
			letterSet += letter;
		}
		for (int i = 0; i < wordVector.size(); i++) {
			string letterSet_copy = letterSet;
			string word_copy = wordVector[i];
			sort(letterSet_copy.begin(), letterSet_copy.end());
			sort(word_copy.begin(), word_copy.end());

			if (letterSet_copy == word_copy) {
				validWord = true;
			}
		}
	}


	cout << "Build a word with the letters:\n";

	for (int i = 0; i < wordLength; i++) { //prints the random word
		cout << letterSet[i] << " ";
	}
	cout << endl<< "Word: ";
	cin >> userWord;

	for (int i = 0; i < userWord.length(); i++ ) {  //converts the input to uppercase letters
		userWord[i] = toupper(int (userWord[i]));
	}

	for (int i = 0; i < wordVector.size(); i++) { //tests if the word is in the dictionary
		if (wordVector[i] == userWord) {
			wordInDictionary = true;
			break;
		}
		else {
			continue;
		}
	}

	if (wordInDictionary) {  //if the word exists compare both words
		string userWord_copy = userWord;
		string letterSet_copy = letterSet;
		sort(userWord_copy.begin(), userWord_copy.end());
		sort(letterSet_copy.begin(), letterSet_copy.end());

		if ( letterSet_copy == userWord_copy) {
			cout << "Correct!!\n";
		}
		else {
			cout << "Invalid word...\n";
		}
	}
	else {
		cout << "Invalid word...\n";
	}

}



void func5(vector<string> wordVector){

	cout << endl << "You chose game number 5." << endl << endl;

	cout << "======================\n";
	cout << "==    WILDCARDS     ==\n";
	cout << "======================\n";

	string wildWord;
	cout << "Please type in your wildcard word: ";
	getline(cin, wildWord);

	char wildWord_C[100];
	strcpy(wildWord_C, wildWord.c_str());

	char NormalWord_C[100];

	for(int j = 0; j < wildWord.length(); j++)
			wildWord.at(j) = toupper(wildWord.at(j));

	cout << "The matching words are: " << endl;

	for(size_t i = 0; i < wordVector.size(); i++){

		string currentWord = wordVector.at(i);

		strcpy(NormalWord_C, currentWord.c_str());

		if(wildcardMatch(NormalWord_C, wildWord_C))
			cout << wordVector.at(i) << endl;

	}

}

bool wildcardMatch(const char *str, const char *strWild) // by JAS
{
 // We have a special case where string is empty ("") and the mask is "*".
 // We need to handle this too. So we can't test on !*str here.
 // The loop breaks when the match string is exhausted.
	while (*strWild)
	{
	// Single wildcard character
			if (*strWild== '?')
			{
				// Matches any character except empty string
				if (!*str)
					return false;

				// OK next
				++str;
				++strWild;
			}else if (*strWild== '*'){
				// 1. The wildcard * is ignored.
				// So just an empty string matches. This is done by recursion.
				// Because we eat one character from the match string,
				// the recursion will stop.
				if (wildcardMatch(str,strWild+1))
					// we have a match and the * replaces no other character
					return true;
				// 2. Chance we eat the next character and try it again,
				// with a wildcard * match. This is done by recursion.
				// Because we eat one character from the string,
				// the recursion will stop.
				if (*str && wildcardMatch(str+1,strWild))
					return true;
				// Nothing worked with this wildcard.
				return false;
			}
			else
			{
				// Standard compare of 2 chars. Note that *str might be 0 here,
				// but then we never get a match on *strWild
				// that has always a value while inside this loop.
				if (toupper(*str++)!=toupper(*strWild++))
					return false;
			}
	}
	// Have a match? Only if both are at the end...
 return !*str && !*strWild;
}

int main() {

	string filename;
	cout << "Please insert the file name: ";
	getline(cin, filename);
	ifstream f(filename);
	if(! f.is_open()){

		cerr << "file not found!" << endl;
		exit(1);
	}

	playwords(f);

	f.close();

	return 0;
}



//just a GitHub test