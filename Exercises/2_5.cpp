#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    //variable declaration
    double a, b, c; //coeficients of the equation
    int type; // 0 if 2 real equal solutions;
              // 1 if 2 real differen solutions
              // 2 if 2 complex solutions  
    double root1, root2; //solutions of the equation
    double real; //real part of a complex root
    double discre; //solucao do binomio discriminate
    string out; //stores the output message

    //input
    cout << "Intrduza os coeficientes (a b c): ";
    cin >> a >> b >> c;
    
    //determination of the solution type
    discre = (b*b) - 4 * a * c;

    if (discre == 0) {
        type = 0;
        out = "A equação tem duas raízes reais iguais: ";
    }
    else if (discre > 0) {
        type = 1;
        out = "A equação tem duas raízes reais diferentes: ";
    }
    else if (discre < 0) {
        type = 3;
        out = "A equação tem duas raizes complexas conjugadas: ";
    }

    switch (type) {
        case 1:
            root1 = (-(b*b))/(2*a);
            root2 = (-(b*b))/(2*a);
            break;
        case 2:
            root1 = (- b + sqrt(discre)/ (2 * a));
            root2 = (- b - sqrt(discre)/ (2 * a));
            break;
        case 3 :
            real = -b /(2*a);
            root1 = (sqrt(abs(discre)))/(2*a);
            break;
    }    

    //output the result 
    if (type == 0 || type == 1) {
        cout << out << root1 << " e " << root2 << endl;
    }
    else if (type == 3) {
        cout << out << real << '+' << root1 <<"i e " << real << '-' << root1 << "i" << endl;
    }


    return 0;

}