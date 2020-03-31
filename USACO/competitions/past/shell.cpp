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

int n, a[101], b[101], g[101];
string sim[3];

int main() {
    ifstream fin("shell.in");
    ofstream fout("shell.out");

    fin >> n;

    for (int i = 0; i < 3; i++) {
        sim[i] = to_string(i);
    }

    for (int i = 0; i < n; i++) {
        fin >> a[i] >> b[i] >> g[i];
    }

    int max = 0, cur = 0;

    for (int j = 0; j < 3; j++) {
        sim[j] = "g";

        for (int i = 0; i < n; i++) {
            string temp = sim[a[i] - 1];
            sim[a[i] - 1] = sim[b[i] - 1];
            sim[b[i] - 1] = temp;

            if (sim[g[i] - 1] == "g") {
                cur++;
            }

            cout << sim[0] << " " << sim[1] << " " << sim[2] << endl;
        }

        if (cur > max) {
            max = cur;
        }

        cur = 0;

        cout << endl;

        for (int i = 0; i < 3; i++) {
            sim[i] = to_string(i);
        }
    }

    fout << max << "\n";

    return 0;
}