==================================================
=================   CROSSWORSS   =================
==================================================  

INTRODUCTION
This project consists of two programmes: cwcreator and cwplayer. 

-cwcreator is used to create a crosswords board, it requires a synonyms dictionary file to verify if words are valid. 
You provide the starting coordinates of a word and the word itself and it gets added to the board. You can also remove 
words or ask for all valid words that fit in a specific space. You can save the board at any time and continue later 
or save the board as final to play it!

-cwplayer allows you to play a board created by cwcreator. It loads a finished board giving a synonym for each word, 
you have to complete the board with the given information if you are having trouble you can get clues. After the board 
is complete it checks if you did it correctly, if you did it saves your score.  

DEVELOPMENT STATE OF THE PROGRAMS 
-Cwcreator extracts all the words and synonyms to a map, the first element of the map is a simple string which is 
the word and the other is a vector of strings which are all the synonyms of that word. We use that to verify if the 
words introduced in the board are valid, the class dictionary does all this. There is also another class called 
board which manages everything that has to do with the board. Everything is implemented and works really well, also, 
invalid inputs have no effect. 

-Cwplayer is also fully implemented, you can play through the board and check your time in the end. It saves the results
 if you successfully solved the puzzle. We created a class called Player which manages everything that has to do with 
 the "player" playing the game. It manages how many clues a player has used and the time it took to complete the puzzle
 if the player has successfully completed it.

It's important to note this project was developed in unix systems both Linux and mac OS so we recommend you run it in one 
of those operating systems. If you run it on a mac the ctrl-D key emits a cin.eof() flag that can not be reversed so if
you are using one of those devices type "end" to finish the creation of a board instead of ctrl-D. We added this feature 
to increase compatibily. The program was not tested on windows so we can not ensure it works on that platform.  


AUTHORS
 -Eduardo Ribeiro -> up201705421@fe.up.pt
 -Leonardo Moura -> up201706907@fe.up.pt



