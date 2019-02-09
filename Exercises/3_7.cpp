#include <iostream>

using namespace std;

double factorial_ite(double n) {
    double  res = 1;
    for (n ;n >= 1; n--) {
            res = res * n;
        }

    return res;
}

int factorial_rec(int n) {
    if (0 == n) {
        return 1;
    }
    else {
        return n * (factorial_rec(n - 1));
    }
}


int main() {
    double num;

    cout << "Fatorial: ";
    cin >> num;
    cout << "Iterativo: " << factorial_ite(num) << endl;
    cout << "Recusrivo: " << factorial_rec(num) << endl;

    return 0;
}