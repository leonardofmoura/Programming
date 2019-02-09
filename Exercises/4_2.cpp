#include <iostream>
#include <string>

using namespace std;


bool sequenceSearch(string s, int nc, char c) {
    int len = s.length(); //length of the s tring
    int counter = 0;           //inicializing counter

    for (int i = 0; i <= (len - 1); i++) { //loop determines how many 
       if (s[i] == c) {                    //c characters are in the loop
           counter++;
           
           if (counter == nc) {
               return true;
           }
       }
       else {
           counter = 0; //resets counter when it finds a char != c
       }                                    
    }

    return false;
}



int main() {
    string word;
    char c;
    int nc;

    cout << "Insert a string: ";
    cin >> word;
    cout << "Character to search: ";
    cin >> c;
    cout << "Number of times to test: ";
    cin >> nc;

    cout << endl << sequenceSearch(word,nc,c) << endl;

    return 0;
}