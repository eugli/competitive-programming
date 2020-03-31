/*
ID: lieugen1
TASK: blist
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int start[101], endt[101], buckets[101];

int main() {
    ifstream fin("blist.in");
    ofstream fout("blist.out");

    int n;
    fin >> n;

    int a, b, c;

    for (int i = 0; i < n; i++) {
        fin >> a >> b >> c;
        start[i] = a;
        endt[i] = b;
        buckets[i] = c;
    }

    int total_buckets = 0;
    int max = 0;

    for (int time = 1; time <= 1000; time++) {
        for (int i = 0; i < n; i++) {
            if (start[i] == time) {
                total_buckets += buckets[i];
            }
        }

        if (total_buckets > max) {
             max = total_buckets;
        }

        for (int i = 0; i < n; i++) {
            if (endt[i] == time) {
                total_buckets -= buckets[i];
            }
        }
    }

    fout << max << "\n";

    return 0;
}