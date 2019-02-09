#include <iostream>
#include <string>

using namespace std;

int StrSize(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}


bool isHydroxide_stl(string compound) {
    int test = compound.length();
    test--;

    if (compound[test - 1] == 'O' && compound[test] == 'H') {
        return true;
    }
    else {
        return false;
    }

}

bool isHydroxide(char compound[] ) {
    int test = (StrSize(compound));
    test--;

    //cout << "Test: " << test << endl;

    if (compound[test - 1] == 'O' && compound[test] == 'H') {
        return true;
    }
    else {
        return false;
    }

}

void decompose(string compound) {
    int len = compound.length();
    len--;  //decrease len to use in the loop 
    
    cout << "Components: ";

    for (int i = 0 ; i <= len; i++) {
        char curr_elem = compound[i];
        char next_elem = compound[i+1];

        if (isupper(curr_elem) && isupper(next_elem)) {
            cout << ' ' << curr_elem;
        }
        else if (isupper(curr_elem) && islower(next_elem)) {
            cout << ' ' << curr_elem << next_elem;
            i++;
        }
    }

}


int main() {
    char comp1[] = "KOH";
    char comp2[] = "H2O2";
    char comp3[] = "NaCl";
    char comp4[] = "C9H8O4";
    char comp5[] = "MgOH";

    string comp1_cpp = "KOH";
    string comp2_cpp = "H2O2";
    string comp3_cpp = "NaCl";
    string comp4_cpp = "C9H8O4";
    string comp5_cpp = "MgOH";

    //cout << "Compound: " ;
    //cin >> comp;
    //cout << StrSize(comp) << endl;
    //cout << isHydroxide(comp) << endl;

    cout << comp1 << ' ' << isHydroxide(comp1) << endl;
    cout << comp2 << ' ' << isHydroxide(comp2) << endl;
    cout << comp3 << ' ' << isHydroxide(comp3) << endl; 
    cout << comp4 << ' ' << isHydroxide(comp4) << endl;
    cout << comp5 << ' ' << isHydroxide(comp5) << endl;

    cout << endl;

    cout << comp1_cpp << ' ' << isHydroxide_stl(comp1_cpp) << endl;
    cout << comp2_cpp << ' ' << isHydroxide_stl(comp2_cpp) << endl;
    cout << comp3_cpp << ' ' << isHydroxide_stl(comp3_cpp) << endl;
    cout << comp4_cpp << ' ' << isHydroxide_stl(comp4_cpp) << endl;
    cout << comp5_cpp << ' ' << isHydroxide_stl(comp5_cpp) << endl;

    return 0;

}