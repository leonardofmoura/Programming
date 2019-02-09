#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    Board cenas(12,12);

    cenas.addWordHorizontal("cona", 9,2);
    cenas.addWordVertical("pila", 8,6);
    cenas.addBlackCell(7,7);
    cenas.print();
    cenas.printWords();
    cenas.printColumn(4);

    cenas.save("Board.txt", "dic.txt");

    //cout << endl << endl;
    //cenas.resize(5,5);
    //cenas.print();

    return 0;
}
