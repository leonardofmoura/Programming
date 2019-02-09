#include <iostream>
#include <cmath>

using namespace std;

bool readFrac(int &numerator, int &denominator) {
    char frac;

    cin >> numerator >> frac >> denominator;

    //cout << numerator << endl << denominator << endl;

    if ('/' == frac ) {
        return true;
    }
    else {
        numerator = 0;
        denominator = 0;
        return false;
    }

}

void writeFrac(int numerator, int denominator) {
    cout << numerator << '/' << denominator << endl;
}

int gcd(int a, int b) {  //greatest common divisor of a and B
    while (b != 0) {
        unsigned r = a % b;
        a = b;
        b = r;
    }
    return a;
} 


void reduceFrac(int &numerator, int &denominator) {
    int divisor = gcd(abs(denominator), abs(numerator));

    denominator = denominator / divisor;
    numerator = numerator / divisor;

}

void multFrac(int numer1, int denom1, int numer2, int denom2) {  
    int newDenom = denom1 * denom2;
    int newNumer = numer1 * numer2;

    reduceFrac(newNumer, newDenom);
    writeFrac(newNumer, newDenom);
}

void addFrac(int numer1, int denom1, int numer2, int denom2) {
    int newNumer1 = numer1 * denom2;
    int newNumer2 = numer2 * denom1;

    int newDenom = denom1 * denom2;
    int newNumer = newNumer1 + newNumer2;

    reduceFrac(newNumer, newDenom);
    writeFrac(newNumer, newDenom);
}

void subFrac(int numer1, int denom1, int numer2, int denom2) {
    int newNumer2 = 0 - numer2;

    addFrac(numer1, denom1, newNumer2, denom2);
}

void divFrac(int numer1, int denom1, int numer2, int denom2) {
    int newDenom2 = numer2;
    int newNumer2 = denom2;

    multFrac(numer1, denom1, newNumer2, newDenom2);
}


int main() {
    int numer1; 
    int denom1;
    int numer2;
    int denom2;
    
    cout << "Fraction1: ";
    readFrac(numer1,denom1);
    cout << endl << "Fraction2: ";
    readFrac(numer2,denom2);
    cout << endl << endl;

    cout << "Frac1 + Frac2 = ";
    addFrac(numer1, denom1, numer2, denom2);
    cout << "Frac1 - Frac2 = ";
    subFrac(numer1, denom1, numer2, denom2);
    cout << "Frac1 * Frac2 = ";
    multFrac(numer1, denom1, numer2, denom2);
    cout << "Frac1 / Frac2 = ";
    divFrac(numer1, denom1, numer2, denom2);
    cout << endl;

    return 0;    
}