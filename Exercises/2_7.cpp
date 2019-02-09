#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const unsigned RESULT_PRECISION = 5;
    const double PI = acos(-1);
    
    cout << "ang        sen     cos     tan\n";

    for (float theta = 0; theta <= 90; theta = theta + 15) 
    {
        double rad = (theta * PI) / 180;

        float cosine = cos(rad);
        float sine = sin(rad);
        string tangent_inf = "infinito";
        float tangent = tan(rad);


        cout << fixed << setprecision(RESULT_PRECISION);
        cout << theta << "   " << sine << "   ";

        if (theta == 90) {
            cout << cosine << "   " << tangent_inf << endl;
        }
        else {
            cout << cosine << "   " << tangent << endl;
        }
    }

    return 0;
}