#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <string>
#include <utility>
using namespace std;

map<string, vector<string> > createDic(ifstream& in);
vector<string> getSynonyms(string line);
bool wildcardMatch(const char *str, const char *strWild);

class Dictionary{

public:
	Dictionary();															//default constructor
																			//-----------
	Dictionary(ifstream& in);												//creates a dictionary with the words and synonyms from the file inserted
																			//------------
	//bool checkWord(const string &word) const; 								//checks if a user inserted word is valid (if it belongs to the dictionary)
																			//------------
	//void help(const Board &b, char line, char column, char direction);		//help the user by showing him/her a list of words that can be added,
			//nao fazer com board como parametro...							//taking into account the current contents of the board
    																			//------------
	map<string, vector<string> > getDic() const;								//returns the dictionary

private:
	map<string, vector<string> > dictionary;


};


#endif /* DICTIONARY_H_ */
