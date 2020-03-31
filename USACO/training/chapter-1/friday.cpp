/*
ID: lieugen1
TASK: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_leap(int year) {
    return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}

int main() {
    ifstream fin ("friday.in");
    ofstream fout ("friday.out");

    int year;
    fin >> year;

    int days[7] = {0, 0, 0, 0, 0, 0 ,0};
    int s_day = 2;

    for (int i = 1900; i < 1900 + year; i++) {
        for (int j = 1; j < 13; j++) {
            int day_13 = (s_day + 12) % 7;
            days[day_13]++;

            if (j == 9 || j == 4 | j == 6 || j == 11) {
                s_day += 2;
            } else if (j == 2) {
                if (is_leap(i)) {
                    s_day += 1;
                }
            } else {
                s_day += 3;
            }
        }
    }

    for (int i = 0; i < 7; i++) {
        fout << days[i];
        if (i == 6) {
            fout << "\n";
        } else {
            fout << " ";
        }
    }

    return 0;
}