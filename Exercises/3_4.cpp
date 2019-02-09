#include <iostream>
#include <cmath>

using namespace std;

double round(double x, unsigned n) {
    double rounded = floor(x * pow(10,n) + 0.5) / pow(10,n);

    return rounded;
}

int main() {
    double num;    //number to be rounded 
    int decimal;  //decimal precision   

    //input
    cout << "Introduza o número a arredondar: ";
    cin >> num;
    cout << "introduza o numero de casas decimais: ";
    cin >> decimal;

    //output
    cout << endl << "Arredondamento: " << round(num,decimal) << endl;

    return 0; 
}