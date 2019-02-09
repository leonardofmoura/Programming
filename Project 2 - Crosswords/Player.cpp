#include "Player.h"


//besides giving the player a name, sets the number of clues asked to 0; time is not initialized, because it is later going to have a value,
//when the user completes the puzzle
Player::Player(string playerName): name(playerName), altClues(0){}




void Player::setFinalTime(duration<double> timeUsed){

	time = timeUsed;
}




void Player::incAltClues(){

	altClues++;

}



string Player::getPlayerName(){

	return name;

}




duration<double> Player::getTime(){


	return time;
}




int Player::getAltClues(){

	return altClues;
}
