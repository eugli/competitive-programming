/*
ID: lieugen1
TASK: barn1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int m, s, c, p;
int occ[200];

void make_board() {
    int gap = 0, mgap = 0, sgap = 0, egap = 0;

    for (int i = 0; i < s; i++) {
        if (!occ[i]) {
            gap++;
        } else {
            if (gap > mgap) {
                mgap = gap;
                egap = i - 1;
                sgap = i - gap;
            }

            gap = 0;
        }
    }

    cout << mgap << " " << sgap << " " << egap;

//    if (gap > mgap) {
//        mgap = gap;
//        egap = s - 1;
//        sgap = s - gap + 1;
//    }

    for (int i = sgap; i <= egap; i++) {
        occ[i] = -1;
    }
}

int main() {
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");

    fin >> m >> s >> c;

    for (int i = 0; i < c; i++) {
        fin >> p;

        occ[p - 1] = 1;
    }

    int b = 1;

    for (int i = 0; i < s; i++) {
        if (!occ[i]) {
            occ[i] = -1;
        } else {
            break;
        }
    }

    for (int i = s - 1; i >= 0; i--) {
        if (!occ[i]) {
            occ[i] = -1;
        } else {
            break;
        }
    }

    while (b < m) {
        make_board();
        b++;
    }

    int ans = 0;

    for (int i = 0; i < s; i++) {
        cout << i + 1 << ": " << occ[i] << "\n";

        if (occ[i] != -1) {
            ans++;
        }
    }

    fout << ans << "\n";

    return 0;
}