#include <iostream>
using namespace std;

int main() {
    int h1, m1, s1; //first time
    int h2, m2, s2; //second time
    int Days, Hours, Minutes, Seconds; //output time

    cout << "Tempo 1 (horas minutos segundos) ? ";
    cin >> h1 >> m1 >> s1;
    cout << "Tempo 2 (horas minutos segundos) ? ";
    cin >> h2 >> m2 >> s2;

    Seconds = (s1 + s2) % 60;
    if (((s1 + s2)-60) >= 1)
        Minutes = ((m1 + m2) % 60) + 1;
    else 
        Minutes = (m1 +m2) % 60;

    if (((m1 +m2) - 60) >= 1) 
        Hours = ((h1 + h2) % 24) + 1;
    else 
        Hours = ((h1 + h2) % 24);

    if (((h1 + h2) - 24) >= 1)
        Days = 1;
    else
        Days = 0;

    //Output
    cout << "Soma dos tempos: " << Days << " dias, " << Hours << " horas, ";
    cout << Minutes << " minutos e " << Seconds << " segundos\n";
    
    return 0; 
}