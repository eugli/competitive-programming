/*
ID: lieugen1
TASK: milk
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> prices;

int main() {
    ifstream fin("milk.in");
    ofstream fout("milk.out");

    fin >> n >> m;

    int tc = 0, c = 0;

    prices.resize(m);

    for (int i = 0; i < m; i++) {
       fin >> prices[i].first >> prices[i].second;
    }

    sort(prices.begin(), prices.end());

    while (n != 0) {
        int unit = prices[c].second;
        int cost = prices[c].first * prices[c].second;

        if (unit < n) {
            n -= unit;
            tc += cost;
        } else {
            tc += n * prices[c].first;
            break;
        }

        c++;
    }

    fout << tc << "\n";

    return 0;
}