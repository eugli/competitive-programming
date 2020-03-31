/*
ID: lieugen1
TASK: convention
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n, m, c, buses[100000], wait[100000];

int main() {
    ifstream fin("convention.in");
    ofstream fout("convention.out");

    fin >> n >> m >> c;

    int times[n], p = 0, max_wait = 0;

    for (int i = 0; i < n; i++) {
        fin >> times[i];
    }

    for (int time = 0; time < 100000; time++) {
        for (int i = 0; i < n; i++) {
            if (times[i] == time) {
                buses[p]++;
            }

            if (buses[p] == c) {
                p++;
                cout << time << endl;
                cout << times[i] << endl;
                wait[i] = time - times[i];
            }
        }
    }

    for (int i = 0; i < 10000; i++) {
        if (wait[i] > max_wait) {
            max_wait = wait[i];
        }
    }

    fout << max_wait << endl;

    return 0;
}