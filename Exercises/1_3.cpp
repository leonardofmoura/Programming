#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double ro, radius;
    double mass;

    //input
    cout << "Insert the density of the sphere(kg/m^3):";
    cin >> ro;
    cout << endl;
    cout << "insert the radius of the sphere(m):";
    cin >> radius;

    //compute the mass 
    mass = ((4/3) * (ro * M_PI * pow (radius, 3.0)));

    //display the mass
    cout << M_PI << endl;
    cout << "The mass of the sphere is " << mass << " Kg\n";

    return 0;
}
