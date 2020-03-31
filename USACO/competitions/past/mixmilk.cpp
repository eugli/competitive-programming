/*
ID: lieugen1
TASK: mixmilk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int capacity[3], amount[3];

int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

    int cap, am;

    for (int i = 0; i < 3; i++) {
        fin >> cap >> am;
        capacity[i] = cap;
        amount[i] = am;
    }

    for (int i = 0; i < 4; i++) {
        amount[(i + 1) % 3] += amount[i % 3];
        if (amount[(i + 1) % 3] > capacity[(i + 1) % 3]) {
            amount[i % 3] = amount[(i + 1) % 3] - capacity[(i + 1) % 3];
            amount[(i + 1) % 3] = capacity[(i + 1) % 3];
        } else {
            amount[i % 3] = 0;
        }

        for (int i = 0; i < 3; i++) {
            cout << amount[i] << "\n";
        }
    }

    for (int i = 0; i < 3; i++) {
        fout << amount[i] << "\n";
    }

    return 0;
}