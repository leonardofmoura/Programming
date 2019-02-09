//now solve the same problem using the switch statement

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
        double operand1, operand2;
        char op;
        double result;
        bool validOperation = true;

        //input
        cout << ">>>";
        cin >> operand1 >> op >> operand2;

        //if the operation is valid compute the result
        switch (op) {
        case '+':
                result = operand1 + operand2;
                break;
        case '-':
                result = operand1 - operand2;
                break;
        case '*':
                result = operand1 * operand2;
                break;
        case '/':
                result = operand1 / operand2;
                break;
        default:
          validOperation = false;
        }

        //shpow result or error message
        if (validOperation) {
          cout << operand1 << ' ' << op << ' ' << operand2 << " = " << endl;
          cout << result << endl;
        }
        else
          cerr << "Invalid Operation! \n";
          
        return 0;
}
