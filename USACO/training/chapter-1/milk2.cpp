/*
ID: lieugen1
TASK: milk2
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

typedef struct Milking {
    int begin;
    int end;
} Milking;

int n;
const int MAX = 5000;
Milking milking[MAX];

int tmilk, tnomilk;

int milkcomp (const void *va, const void *vb) {
    Milking *a, *b;

    a = (Milking*)va;
    b = (Milking*)vb;

    if (a -> begin > b -> begin) return 1;
    if (a -> begin < b -> begin) return -1;
    return 0;
}

int main() {
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> milking[i].begin >> milking[i].end;
    }

    qsort(milking, n, sizeof(Milking), milkcomp);

    int t;
    Milking cur;
    cur = milking[0];

    for (int i = 1; i < n; i++) {
        if (milking[i].begin > cur.end) {
            t = milking[i].begin - cur.end;

            if (t > tnomilk) {
                tnomilk = t;
            }

            t = cur.end - cur.begin;

            if (t > tmilk) {
                tmilk = t;
            }

            cur = milking[i];
        } else {
            if (milking[i].end > cur.end) {
                cur.end = milking[i].end;
            }
        }
    }

    t = cur.end - cur.begin;

    if (t > tmilk) {
        tmilk = t;
    }

    fout << tmilk << " " << tnomilk << "\n";

    return 0;
}