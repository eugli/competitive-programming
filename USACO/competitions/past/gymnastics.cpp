/*
ID: lieugen1
TASK: gymnastics
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int n, k, perf[10][20], rankings[20];
typedef pair<int, int> pairs;

void display(const set<pairs>& s)
{
    bool found = false;

    // range-based for loop
    for (auto const &x : s) {
        found = true;
        cout << "(" << x.first << ", "
             << x.second << ")"
             << " ";
    }

    if (not found) {
        cout << "No valid pair\n";
    }
}

int main() {
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");

    set<pairs> s;
    set<pairs> bad;

    fin >> k;
    fin >> n;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            fin >> perf[i][j];
            cout << perf[i][j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = j + 1; l < n; l++) {
                pairs x = make_pair(perf[i][j], perf[i][l]);
                if (s.count(make_pair(x.second, x.first))) {
                    s.erase(make_pair(x.second, x.first));
                    bad.insert(x);
                    bad.insert(make_pair(x.second, x.first));
                } else {
                    if (!bad.count(x)) {
                        s.insert(x);
                    }
                }
            }
        }

        display(s);
        cout << endl;
    }

    display(s);
    fout << s.size() << "\n";

    return 0;
}
