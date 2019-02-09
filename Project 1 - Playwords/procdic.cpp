#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


//if word has a colon deletes it
string colon_elim(string word) {
	if (word.back() == ';') {
		word.erase(word.length()-1);
		return word;
	}
	else {
		return word;
	}
}

string space_elim(string word){

	if(word.at(word.length()-1) == ' ')
		word.erase(word.length()-1);

	return word;
}

void word_split(vector<string>& extractedWords, string sentence){

	int wordStart = 0;

	for(int i = 0; i < sentence.length(); i++){

		if(' ' == sentence[i]){
			if(';' == sentence[i-1]){

				extractedWords.push_back(space_elim(colon_elim(sentence.substr(wordStart, i- wordStart))));
				wordStart = i+1;
			}
		}

		 if(i == (sentence.length() -1)){

		        	extractedWords.push_back(space_elim(colon_elim(sentence.substr(wordStart, sentence.length() - 1- wordStart))));
		 }

	}

}

//if the line is valid
bool valid_sentence(string sentence){
	if (int(sentence[0]) == 13) {
		return false;
	}
	else {
		for (int i = 0; i < sentence.length(); i++) {

			int ascii = int(sentence[i]);
			if (! (isupper(ascii) || 32 == ascii || 59 == ascii || 45 == ascii || 39 == ascii || 13 == ascii) ) { //tests all valid characters
				return false;
			}
			else {
				continue;
			}
		}
	}
	return true; //return true if it only finds valid chars
}

bool valid_word(string word){
	for (int i = 0; i < word.length() ; i++) {
		int ascii = int(word[i]);

		if (!(isupper(ascii))) {
			return false;
		}
		else {
			continue;
		}
	}

	return true; //if the cicle is completed all chars are valid so it returns true
}

//returns a vector with only the extracted words
vector<string> clean_extracted_words (vector<string>& extractedWords) {
	vector<string> cleanWords;

	for (int i = 0; i < extractedWords.size(); i++) {

		if (valid_word(extractedWords[i])) {
			cleanWords.push_back(extractedWords[i]);
		}
		else {
			continue;
		}

	}

	return cleanWords;
}


set<string> remove_duplicates(vector<string>& extractedWords) {
	set<string> finalWords;

	for (int i = 0; i < extractedWords.size(); i++) {
		finalWords.insert(extractedWords[i]);
	}

	return finalWords;
}


// reads from the dictionary file; each word is stored one at a time in ProcString; checks if valid, and in that case it store the word in the vector
vector<string> read_dic(ifstream& dictionary) {

	vector<string> extractedWords; //stores valid words
	string procString;  //word being processed
	int contador = 0;
	char letraAtual = '@';

	//int i = 1;  word counter for debug purposes
	while(getline(dictionary, procString)){

		if (valid_sentence(procString)) {

			word_split(extractedWords, procString);

			if(procString.at(0) != letraAtual && isupper(int(procString.at(0))) && (int)procString.at(0) == (int)letraAtual +1){
				letraAtual = procString.at(0);
				cout << endl << letraAtual << endl;
				contador = 0;
			}

			contador++;

			if(contador % 100 == 0)
				cout << ". ";
		}
	//i += 1;
	}

	//cout << i << endl;
	cout << endl;
	return extractedWords;
}

int main() {
    string inputDicName, outputDicName;
    ifstream inputDic;
    ofstream outputDic;
	vector<string> extractedWords;
	set<string> finalWords;

    cout << "Dictionary file: ";
    cin >> inputDicName;
    cout << "Word list file: ";
    cin >> outputDicName;

    inputDic.open(inputDicName);

    if(inputDic.fail()){
    	cerr << "Error opening input file...";
    	exit(1);

    }

    cout << "Extracting simple words from file " << inputDicName << endl;

	extractedWords = read_dic(inputDic); //extract all headlines to extracted words

	extractedWords = clean_extracted_words(extractedWords); //clears all invalid words

	cout << "Number of extracted words = " << extractedWords.size() << endl << endl;

	cout << "Sorting words...\n" << endl;

	//sort(extractedWords.begin(),extractedWords.end());  not needed because words in set are automatically sorted

	cout << "Removing duplicates...\n" << endl;

	finalWords = remove_duplicates(extractedWords);

	cout << "Number of non-duplicate simple words = " << finalWords.size() << endl << endl;

	cout << "Saving words into file " << outputDicName << "...\n" << endl << endl;

	outputDic.open(outputDicName);

	if(outputDic.fail()){
		cerr << "Error opening output file...";
		exit(2);
	}

    for (set<string>::iterator i = finalWords.begin(); i != finalWords.end(); i++) {
		outputDic << *i << endl;
	}

	inputDic.close();
	outputDic.close();

	cout << "Done!";

    return 0;
}
