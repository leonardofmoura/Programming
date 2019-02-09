#include "color.h"

void gotoxy(int x, int y) {
    ostringstream oss;
    oss << "\033[" << y << ";" << x <<"H";
    cout << oss.str();
}

void clrscr(void) {
    cout << "\033[2J";
    gotoxy(0,0);
}

void setcolor(string color) {
    cout << color;
}

void setcolor(string color, string background_color) {
    cout << color << background_color;
}

