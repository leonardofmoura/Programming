#include <iostream>
#include <cmath>

using namespace std;

double distance (double x1, double y1, double x2, double y2) {
    double dis = sqrt( pow((x2 -y1), 2) + pow((y2 - y1),2));

    return dis;
}


double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double d1 = distance(x1,y1,x2,y1);
    double d2 = distance(x2,y2,x3,y3);
    double d3 = distance(x1,y1,x3,y3);

    double s = (d1 + d2 +d3) / 2;

    double area = sqrt(s*(s-d1)*(s-d2)*(s-d3));

    return area;
}



int main() {
    //variables
    double x1, y1; //first point
    double x2, y2; //second point
    double x3, y3; //third point 

    //input
    cout << "Insira as coordenadas do primeiro ponto: ";
    cin >> x1 >> y1;

    cout << "Insira as coordenadas do segundo ponto: ";
    cin >> x2 >> y2;

    cout << "Insira as coordenadas do terceiro ponto: ";
    cin >> x3 >> y3;

    double ar = area(x1,y1,x2,y2,x3,y3); 

    cout << endl << "A área do triangulo é " << ar << endl;

    return 0;
}