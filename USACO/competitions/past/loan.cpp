/*
ID: lieugen1
TASK: loan
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

long long int N, K, M;

int main() {
    ifstream fin("loan.in");
    ofstream fout("loan.out");

    fin >> N >> K >> M;

    long long int given = 0, y, ans = 0, min = N / M;

    for (long long int i = 1; i < min; i++) {
        for (long long int j = 0; j < K; j++) {
            y = (N - given) / i;

            if (y < M) {
                long long int rest = M * (K - j);
                given += rest;

                if (given >= N) {
                    ans = i;
                }

                break;
            } else {
                given += y;
            }

            if (given >= N) {
                ans = i;
                break;
            }
        }

        given = 0;
    }

    fout << ans << "\n";

    return 0;
}