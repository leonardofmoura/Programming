//exercise 1.4 of the exercise sheet

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float a, b, c, d, e, f;  //values used in the calculation
    float x, y;              //values to be calculated

    cout << "Consider a system of equations in the form :\n";
    cout << "a·x + b·y = c\n";
    cout << "d·x + e·y = f\n";

    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "c: "; cin >> c;
    cout << "d: "; cin >> d;
    cout << "e: "; cin >> e;
    cout << "f: "; cin >> f;
     
    //calculations
    x = ((c * e) - (b * f)) / ((a * e) - (b * d));
    y = ((a * f) - (c * d)) / ((a * e) - (b * d));

    //test if the system is solvable
    if (isnan(x)) 
        cout << "The system is indeterminate\n";
    else if (isinf(x))
        cout << "The system is impossible\n";
    else {
        //output
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    return 0;
}