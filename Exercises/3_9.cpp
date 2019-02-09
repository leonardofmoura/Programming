//integration aproximation usig the trapezoidal rule

#include <iostream>
#include <cmath>

using namespace std;


double integrateTR(double f(double), double a, double b, int n) {
    double res = 0;
    for (int i = 1; i <= n; i++) {
        double h = (b - a) / n;
        double val = (h / 2) * ( f(a + h * (i - 1)) + f(a + (i * h)));
        res = res + val;
    }
    return res;
}

double g(double x ) {
    double y;
    y = pow(x,2);

    return y;
} 

double h(double x ) {
    double y;
    y = sqrt(4 - pow(x,2));

    return y;
}

int main() {
    double a, b;
    int n;

    cout << "Função g(x) = x ^ 2 (inserir a, b, n): ";
    cin >> a >> b >> n;

    cout << "Função h(x)=sqrt(4 - x ^ 2) (inserir a, b, n): ";
    cin >> a >> b >> n;

    cout << "g(x): " << integrateTR(g, a, b, n) << endl;
    cout << "h(x): " << integrateTR(h, a, b, n) << endl;

    return 0;
    
}