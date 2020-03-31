/*
ID: lieugen1
TASK: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");

    int n;
    fin >> n;

    string students[n];
    int bank[n];

    for (int i = 0; i < n; i++) {
        fin >> students[i];
        bank[i] = 0;
    }

    string giver;
    int amount;
    int people;
    for (int i = 0; i < n; i++) {
        fin >> giver;
        fin >> amount;
        fin >> people;

        for (int i = 0; i < n; i++) {
            if (students[i] == giver && people != 0) {
                bank[i] -= amount;
                bank[i] += amount % people;
            }
        }

        string peep;
        for (int i = 0; i < people; i++) {
            fin >> peep;

            for (int j = 0; j <  n; j++) {
                if (peep == students[j]) {
                    bank[j] += amount / people;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        fout << students[i] << " " << bank[i] << "\n";
    }

    return 0;
}