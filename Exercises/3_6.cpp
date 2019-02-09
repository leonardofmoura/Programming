#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

bool testBissexto(int year) {
    if ((year % 4) == 0 && (year % 100) == 0) {
        return true;
    }
    else if ((year % 4) == 0 && (year % 100) != 0) {
        return true;
    }
    else {
        return false;
    }
}


int monthDays(int month, int year) {
    if (2 == month) {
        if (testBissexto(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else {
        if ((month % 2 ) == 0 ) {
            return 30;
        }
        else {
            return 31;
        }
    }
}

int monthCode(int month, int year) {
    int c;

    switch(month) {
        case 1:
            if (testBissexto(year)) {
                return 6;
            }
            else {
                return 0;
            }
        
        case 2:
            if (testBissexto(year)) {
                return 2;
            }
            else {
                return 3;
            }

        case 3:
            if (testBissexto(year)) {
                return 3;
            }
            else {
                return 3;
            }
        
        case 4:
            if (testBissexto(year)) {
                return 6;
            }
            else {
                return 6;
            }
        
        case 5:
            if (testBissexto(year)) {
                return 1;
            }
            else {
                return 1;
            }

        case 6:
            if (testBissexto(year)) {
                return 4;
            }
            else {
                return 4;
            }

        case 7:
            if (testBissexto(year)) {
                return 6;
            }
            else {
                return 6;
            }

        case 8:
            if (testBissexto(year)) {
                return 2;
            }
            else {
                return 2;
            }

        case 9:
            if (testBissexto(year)) {
                return 5;
            }
            else {
                return 5;
            }

        case 10:
            if (testBissexto(year)) {
                return 0;
            }
            else {
                return 0;
            }

        case 11:
            if (testBissexto(year)) {
                return 3;
            }
            else {
                return 3;
            }

        case 12:
            if (testBissexto(year)) {
                return 5;
            }
            else {
                return 5;
            }
    }
}


int weekDay(int day, int month, int year) {
    int s = year / 100;
    int a = (((year / 100.0) - s) * 100) + 1;
    int d = day;
    int c = monthCode(month, year);

    int ds = (((5 * a) / 4) + c + d - (2 * (s % 4)) + 7) % 7;

    //cout << s << endl << a << endl;

    return ds;    

}

string str_month(int month) {
    switch (month) {
        case 1:
            return "Janeiro";
        case 2:
            return "Fevereiro";
        case 3: 
            return "Março";
        case 4:
            return "Abril";
        case 5:
            return "Maio";
        case 6:
            return "Junho";
        case 7:
            return "Julho";
        case 8:
            return "Agosto";
        case 9:
            return "Setembro";
        case 10:
            return "Outubro";
        case 11:
            return "Novembro";
        case 12: 
            return "Dezembro";
    }

}



void month_callendar(int month, int year) {
    cout << endl << "  " << str_month(month) << '/' << year << endl;
    cout << setw(5) << right << "Dom";
    cout << setw(5) << right << "Seg";
    cout << setw(5) << right << "Ter";
    cout << setw(5) << right << "Qua";
    cout << setw(5) << right << "Qui";
    cout << setw(5) << right << "Sex";
    cout << setw(5) << right << "Sab" << endl;

    for(int i = 1; i <= monthDays(month,year); i++) {
        if (1 == i) {
            int day = weekDay(i, month, year);
            switch (day) {
                case 0:
                    cout << setw(35) << right << i << endl;
                    break;
                case 1:
                    cout << setw(5) << right << i;
                    break;
                case 2:
                    cout << setw(10) << right << i;
                    break;
                case 3:
                    cout << setw(15) << right << i;
                    break;
                case 4:
                    cout << setw(20) << right << i;
                    break;
                case 5:
                    cout << setw(25) << right << i;
                    break;
                case 6:
                    cout << setw(30) << right << i;
                    break;
            }
        }

        else {
            cout << setw(5) << right << i;

            if (weekDay(i, month, year) == 0) {
                cout << endl;
            }
        }
    }
    cout << endl;
}

int print_cal(int year) {
    for (int i = 1; i <= 12; i++) {
        month_callendar(i, year);
    }
}


int main() {
    int day;
    int year;
    int month;

    //cout << "d>>>";
    //cin >> day;
    //cout << "m>>> ";
    //cin >> month;
    cout << "y>>> ";
    cin >> year;

    print_cal(year);
    

    //cout << testBissexto(year) << endl;
    //cout << monthDays(month, year) << endl;


    /*
    switch (weekDay(day, month, year)) {
        case 0:
            cout << "Sábado\n";
            break;
        case 1:
            cout << "Domingo\n";
            break;
        case 2:
            cout << "Segunda\n";
            break;
        case 3:
            cout << "Terça\n";
            break;
        case 4:
            cout << "Quarta\n";
            break;
        case 5:
            cout << "Quinta\n";
            break;
        case 6:
            cout << "Sexta\n";
            break;
    }
    */


    return 0;
}