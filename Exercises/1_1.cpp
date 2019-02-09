//exercise 1.1 from the exercise pdf
//shows the ASCII code of any key introduced

#include <iostream> 
using namespace std;

int main() { 
  char c;  //char introduced by the user

  cout << "Introduce any letter on your keybord " << endl;
  cin >> c;
  cout << "The ASCCI code of that letter is " << static_cast<int> (c) << endl;

  return 0;
}
 