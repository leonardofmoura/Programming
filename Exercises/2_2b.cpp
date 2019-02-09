#include <iostream>
using namespace std;

int main() {
    double in1, in2, in3; //values to be introduced
    double min1 ,min2, min3; // minimum value
    int test; //stores the position os the min value (if its in1 it stores the value 1 etc...)

    //input
    cout << "Insert 3 numbers: ";
    cin >> in1 >> in2 >> in3;

    //calculate the lowest
    min1 = in1;
    if (in2 < min1)
        min1 = in2;
    if (in3 < min1)
        min1 = in3;

    //test which one is the minimum
    if (min1 == in1)
        test = 1;
    else if (min1 == in2)
        test = 2;
    else if (min1 == in3)
        test = 3;

    switch (test) {
        case 1 : {
            if (in2 > in3) {
                min2 = in3;
                min3 = in2; 
                break;
            }
            else {
                min2 = in2;
                min3 = in3;
                break;
            }     
        }
        case 2 : {
            if (in1 > in3) {
                min2 = in3;
                min3 = in1; 
                break;
            }
            else {
                min2 = in1;
                min3 = in3;
                break;
            }     
        }
        case 3 : {
            if (in2 > in1) {
                min2 = in1;
                min3 = in2; 
                break;
            }
            else {
                min2 = in2;
                min3 = in1;
                break;
            }     
        }        
    }

    //output
    cout << "Oredered sequence: " << min1 << ' ' << min2 << ' ' << min3 << endl;
    cout << test << endl ;

    return 0;
}
