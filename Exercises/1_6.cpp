#include <iostream>
#include <math.h>
using namespace std;

int main() {
    //point defenition
    double x1, y1; //point 1
    double x2 ,y2; //point 2
    double x3, y3; //point 3

    //input section
    cout << "Insert the coordinates of the first point (format: x y): ";
    cin >> x1 >> y1;

    cout << "Insert the coordinates of the second point (format: x y): ";
    cin >> x2 >> y2;

    cout << "Insert the coordinates of the third point (format: x y): ";
    cin >> x3 >> y3;

    //distance defenition and calculation
    double d1, d2 ,d3;
    d1 = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    d2 = sqrt(pow((x3-x2),2) + pow((y3-y2),2));
    d3 = sqrt(pow((x3-x1),2) + pow((y3-y1),2));

    //semiperimeter
    double s = (d1 + d2 + d3) / 2;

    //area
    double area = sqrt(s*(s-d1)*(s-d2)*(s-d3));

    //output
    cout << endl << "Area = " << area << endl;

    return 0;
}   