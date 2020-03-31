/*
ID: lieugen1
TASK: whereami
LANG: C++11
 */
#include <bits/stdc++.h>

using namespace std;

int n;
string mail;

int main() {
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");

    fin >> n >> mail;

    mail += "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

    bool valid = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            size_t found = mail.find(mail.substr(j, i), j + 1);
            cout << mail.substr(j, i) << endl;
            cout << found << endl;
            if (found != string::npos && found != j) {
                valid = false;
                break;
            }
        }

        if (valid) {
            fout << i << endl;
            break;
        }

        valid = true;
    }
}