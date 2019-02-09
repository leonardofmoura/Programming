#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <sstream>
#include <fstream>
#include <cctype>
#include <vector>
#include "Dictionary.h"

using namespace std;

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

vector<string> getSynonyms(string line){

	vector<string> synonyms;
	string word;

	while(line.find_first_of(',') != string::npos){

		int ind = 0;

	for(int i = 0; i < line.length(); i++){			//gets the first word

		if(line.at(i) == ','){
			word = line.substr(0, i);
			synonyms.push_back(word);
			ind = i;
			break;
		}
	}

	ind = ind + 2;     				//is at the start of the next word
	line.erase(0, ind);
	}

	if(line != ""){

		word = line;
		synonyms.push_back(word);
	}


	return synonyms;
}

map<string, vector<string> > createDic(ifstream& in){

	map<string, vector<string> > dic;
	vector<string> synonyms;


	string line;

	while(getline(in, line)){

		int i = 0;
		string firstWord = line.substr(0, line.find_first_of(':'));            //gets the first word

		for(int j = 0; j < firstWord.length(); j++)
			firstWord.at(j) = toupper(firstWord.at(j));

		i = (line.find_first_of(':') + 2);      		//skips ':' and ' '

		line.erase(0, i);

		vector<string> synonyms = getSynonyms(line);

		dic.insert(pair<string, vector<string> >(firstWord, synonyms));

	}

			return dic;

}

//creates an empty dictionary
Dictionary::Dictionary(){

	map<string, vector<string> > m;
	dictionary = m;

}


Dictionary::Dictionary(ifstream& in): dictionary(createDic(in)){}


/*bool Dictionary::checkWord(const string &word) const{

	for(map<string, vector<string> >::const_iterator it = dictionary.begin(); it != dictionary.end(); it++){

		if(it->first == word)
			return true;
	}

	return false;
}*/



map<string, vector<string> > Dictionary::getDic() const{

	return this->dictionary;

}

/*void Dictionary::help(const Board &b, char line, char column, char direction){

	int iline, icolumn;     			//represent the index of the chosen line and column
	iline = (int)iline - 65;			//65 is the ascii code for 'A'
	icolumn = (int)icolumn - 97;		//97 is the ascii code for 'a'
	vector<vector <char> > board = b.getBoard();

	if(direction == 'H'){

		for(int i = )


	}



}*/


