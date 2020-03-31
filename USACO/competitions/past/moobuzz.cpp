/*
ID: lieugen1
TASK: moobuzz
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> first;

bool ok (int x) {
    return x % 3 && x % 5;
}

int solve (int n) {
    int num = (n - 1) / 8;
    return first[(n - 1) % 8] + 15 * num;
}

int main() {
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");

    fin >> n;

    for (int i = 1; i < 16; i++) {
        if (ok(i)) {
            first.push_back(i);
        }
    }

    fout << solve(n);

    return 0;
}