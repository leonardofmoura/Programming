//exercise 1.2 of the exercise pdf
//

#include <iostream>
using namespace std;

int main() {
  double A, B , C, med; //variables

  // input
  cout << "Insert A: ";
  cin >> A;
  cout << endl;

  cout << "Insert B: ";
  cin >> B;
  cout << endl;

  cout << "Insert C: ";
  cin >> C;
  cout << endl;

  //calculation
  med = ((A + B + C)/ 3);

  //output
  cout << "media    = " << med << endl;
  cout << "A-media  = " << A - med << endl;
  cout << "B-media  = " << B - med << endl;
  cout << "C-media  = " << C - med << endl;

  return 0;

}
