#include <bits/stdc++.h>

using namespace std;

int N;
map<string, vector<string>> graph;
map<string, int> deg;
map<string, bool> visited;
string names[] = {"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", "Blue", "Bella", "Buttercup"};
ofstream fout("lineup.out");

void dfs(string node);

int main() {
    ifstream fin("lineup.in");

    fin >> N;
    string seq;
    getline(fin, seq);

    sort(names, names + 8);

    for (int i = 1; i <= N; i++) {
        getline(fin, seq);

        int pos = seq.find(" ");
        string nameA = seq.substr(0, pos);
        string nameB = seq.substr(nameA.size() + 23);

        graph[nameA].push_back(nameB);
        graph[nameB].push_back(nameA);
        ++deg[nameA];
        ++deg[nameB];
    }

    for(auto it = deg.cbegin(); it != deg.cend(); ++it)
    {
        cout << it->first << " " << it->second << " " << endl;
    }

    for (int i = 0; i < 8; i++) {
        if (deg[names[i]] == 0) {
            fout << names[i] << endl;
        } else if (!visited.count(names[i]) && deg[names[i]] == 1) {
            dfs(names[i]);
        }
    }

    return 0;
}

void dfs(string node) {
    fout << node << endl;
    visited[node] = true;

    for (auto connNode: graph[node]) {
        if (!visited.count(connNode)) {
            dfs(connNode);
        }
    }
}
