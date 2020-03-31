/*
ID: lieugen1
TASK: berries
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int const kmax = 1000;
int n, k, trees[kmax + 1], previ = -1, cur = 0, biggest[kmax + 1];

void solve(int biggest[]) {
    if (biggest[k - 1] % 2 == 1) {
        biggest[0] = biggest[k - 1] / 2 + 1;
    } else {
        biggest[0] = biggest[k - 1] / 2;
    }

    biggest[k - 1] /= 2;

    sort (biggest, biggest + k);

    for (int i = 0; i < k; i++) {
        cout << biggest[i] << endl;
    }

    cout << "-----------";

    for (int i = 0; i < k / 2; i++) {
        cur += biggest[i];
    }

    if (cur < previ) {
        return;
    } else {
        previ = cur;
        cur = 0;

        solve(biggest);
    }
}

int main() {
    ifstream fin("berries.in");
    ofstream fout("berries.out");

    fin >> n >> k;

    for (int i = 0; i < n; i++) {
        fin >> trees[i];
    }

    sort(trees, trees + n, greater<int>());

    int c = k - 1;

    for (int i = 0; i < n; i++) {
        biggest[c] = trees[i];
        c--;

        if (c == -1) {
            break;
        }
    }

    solve(biggest);

    fout << previ << "\n";

    return 0;
}