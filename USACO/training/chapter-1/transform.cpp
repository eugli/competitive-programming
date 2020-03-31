/*
ID: lieugen1
TASK: transform
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int starting[10][10], ending[10][10];

void rotate(int * original, int degree, int n) {
    if (degree == 90) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                original[i][j] = original
            }
        }
    } else if (degree == 180)
    }
}



int main() {
    ifstream fin ("transform.in");
    ofstream fout ("transform.out");

    fin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            fin >> starting[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            fin >> ending[i][j];
        }
    }
}