#include <iostream>
using namespace std;

int main() {
        double in1, in2, in3; //values to be introduced
        double min; //temporary minimum value

        //input
        cout << "Insert 3 numbers: ";
        cin >> in1 >> in2 >> in3;

        //calculate the lowest
        min = in1;
        if (in2 < min)
                min = in2;
        if (in3 < min)
                min = in3;

        //display
        cout << "The lowest value is: " << min << endl;

        return 0;
}
