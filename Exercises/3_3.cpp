#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double square_root(double num, double delta, int MaxIter) {
    int iter = 0;
    double diff = 100000;
    double rq = 1;
    double rqn = (rq + (num / rq)) / 2;;
    
    while (iter < MaxIter && abs(diff) > delta) {

        if (iter == 0) {
            rqn = (rq + (num / rq)) / 2;
        }
        else {
            rqn = (rqn + (num / rqn)) / 2;
        }    
        diff = num - pow(rqn,2);
        iter = iter + 1;
    }

    return rqn;
}

double diff(double calc_val, double number) {
    double err = abs( calc_val - sqrt(number) );

    return err;

}




int main() {
    double num;
    double sqr; 
    int MaxIter;
    double delta;
    const int RESULT_PRECISION = 10;

    //input
    cout << "Insrir o numero a calcular a raiz quadrada: ";
    cin >> num;
    cout << "Inserir numero maximo de iteracoes: ";
    cin >> MaxIter;
    cout << "Inserir precisão: ";
    cin >> delta;

    //calculation
    sqr = square_root(num, delta, MaxIter);

    //show retult
    cout << fixed << setprecision(RESULT_PRECISION);
    cout << endl << "Raiz quadrada de " << num << " = " << sqr << endl;
    cout << endl << "O desvio do valor real é: " << diff(sqr,num) << endl;
    

    return 0;
}