/*
ID: lieugen1
TASK: default
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

const int MX = 100005;

int N, M, comp[MX], num;
char col[MX];
vector<int> adj[MX];

void dfs (int x) {
    if (comp[x]) {
        return;
    }
    comp[x] = num;
    trav(t, adj[x]);
    if (col[t] == col[x]) {
        dfs(t);
    }
}

int main() {
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");

    fin >> N >> M;
    string s;
    cin >> s;

    for (int i = 1; i < n; i++) {
        col[i] = s[i- 1];
    }
}