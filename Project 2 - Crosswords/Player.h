
#ifndef PLAYER_H_
#define PLAYER_H_


#include <string>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Player{

public:
	Player(string playerName);		//creates a new player, given their name
	void setFinalTime(duration<double> timeUsed);		//sets the final time that the player took to solve the crosswords
	void incAltClues();		//increments by 1 the number of alternative clues the player as asked for
	string getPlayerName(); //returns the player name
	duration<double> getTime(); //returns the time
	int getAltClues(); //gets the number of alternative clues the player as asked for



private:
	string name;		//name of the player
	duration<double> time;		//time that the player took to solve the crosswords
	int altClues;	//number of alternative clues the user as asked for
};



#endif /* PLAYER_H_ */
