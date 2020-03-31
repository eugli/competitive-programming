/*
ID: lieugen1
TASK: wormsort
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, sol = -1;
map<pair<int, int>, int> weights;

void printpath(vector<int>& path)
{
    int size = path.size();
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
        cout << path[i] << " ";
    for (int i = 0; i < size - 1; i++) {
        int weight = weights[make_pair(path[i], path[i + 1])];

        if (weight < min) {
            min = weight;
        }
    }

    if (min > sol) {
        sol = min;
    }

    cout << endl;
}

int isNotVisited(int x, vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return 0;
    return 1;
}

int findpaths(vector<vector<int> >&g, int src,
               int dst)
{
    queue<vector<int> > q;

    vector<int> path;
    path.push_back(src);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];

        if (last == dst)
            printpath(path);

        for (int i = 0; i < g[last].size(); i++) {
            if (isNotVisited(g[last][i], path)) {
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }

    int ans = sol;
    sol = -1;

    return ans;
}

bool ok(int locs[], int n) {
    for (int i = 0; i < n; i++) {
        if (locs[i] != i + 1) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");

    fin >> n >> m;

    int locs[n], sol = -1;

    for (int i = 0; i < n; i++) {
        fin >> locs[i];
    }

    if (ok(locs, n)) {
        fout << sol << "\n";
        return 0;
    }

    vector<vector<int> > g;
    g.resize(n + 1);
    int a, b, w;

    for (int i = 0; i < m; i++) {
        fin >> a >> b >> w;

        g[a].push_back(b);
        pair<int, int> temp = make_pair(a, b);
        weights[temp] = w;
    }

    int final = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (locs[i] != i + 1) {
            int cost = findpaths(g, i + 1,  locs[i]);
            cout << "cost: " << cost << endl;

            if (cost != -1 && cost < final) {
                final = cost;
            }

            int a = i;
            int b = locs[i] - 1;
            int temp = locs[a];
            locs[a] = locs[b];
            locs[b] = temp;
        }
    }

    fout << final << "\n";

    return 0;
}