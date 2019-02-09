#include <iostream>

using namespace std;

int main() {
    double weight;
    double cost;

    //input
    cout << "Peso da mercadoria: ";
    cin >> weight;

    //compute the cost
    if (weight < 500)
        cost = 5;
    else if (weight <= 1000)
        cost = 5 + 1.5*((weight - 500) / 100);
    else if (weight > 1000)
        cost = 12.5 + 5 * ((weight - 1000) / 250);
    
    //output the cost
    cout << endl << "A mercadoria custa " << cost << endl;
    

    return 0;
}