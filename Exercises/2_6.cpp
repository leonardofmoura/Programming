//Tests if a number is prime 

#include <iostream>
#include <cmath>
using namespace std;

bool TestPrime(unsigned long int n) {
    bool prime = true; //True if the number is prime, false if it's not

    if (n == 2) {
        return prime;
    }
    else {
        //loop
        int i;
        for (i = 2; i <= sqrt(n); i = i + 1) {
            if ((n % i) == 0 ) {
                prime = false;
                break;
            }
        }
        return prime;
    }

}


void ShowPrime() { //a)
    unsigned long int n;

    //input 
    cout << "Number to test prime: ";
    cin >> n;

    bool prime = TestPrime(n);


    //output 
    if (prime) {
        cout << "Prime!\n";
    }
    else {
        cout << "Not prime!\n";
    }  
}


void prime_100() { //b)
    int primNum = 0;
    for (int i = 1; primNum <= 100; i++) {
        if (TestPrime(i)) {
            primNum++;
            cout << i << ", ";
        }
    }
    cout << endl;
}

void prime_10000() { //c)
        for (int i = 1; i <= 10000; i++) {
        if (TestPrime(i)) {
            cout << i << ", ";
        }
    }
    cout << endl;
} 



int main() {
    int select; //stores the option selected by the user

    cout << "Alinea a correr[1-a), 2-b), 3-c)] : ";
    cin >> select;

    //run the selected funcion
    switch (select) {
        case 1 : 
            ShowPrime();
            break;
        case 2 : 
            prime_100();
            break;
        case 3:
            prime_10000();
            break;
        default :
            cerr << "Valor invalido\n";
            break;
    }

    return 0;
}