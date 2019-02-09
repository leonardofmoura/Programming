#include <iostream>
using namespace std;

int main() {
    double in1, in2, in3; //values to be introduced
    double min1 ,min2 , min3; //temporary minimum value
    int testMin, testMax; //stores de position of the minimum
    bool possible; //true if it is possible to build the triangle

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
        testMin = 1;
    else if (min1 == in2)
        testMin = 2;
    else if (min1 == in3)
        testMin = 3;

    //order the values
    switch (testMin) {
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

    //test which one is the maximum
    if (min3 == in1)
        testMax = 1;
    else if (min3 == in2)
        testMax = 2;
    else if (min3 == in3)
        testMax = 3;

    //tests if the triangle is possible
    switch (testMax) {
        case 1 : {
            if ((in2 + in3) < in1) {
                possible = false;
                break;
            }
            else {
                possible = true;
                break;
            }     
        }
        case 2 : {
            if ((in1 + in3) < in2) {
                possible = false;
                break;
            }
            else {
                possible = true;
                break;
            }     
        }
        case 3 : {
            if ((in1 + in2) < in3) {
                possible = false;
                break;
            }
            else {
                possible = true;
                break;
            }     
        }        
    }

    //output
    if (possible)
        cout << "The triangle exists!\n";
    else 
        cout << "That triangle is impossible\n";

        return 0;
}
