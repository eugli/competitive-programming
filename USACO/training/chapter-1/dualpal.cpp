/*
ID: lieugen1
TASK: dualpal
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int n, s;

string convert(int n, int b) {
    string r = "";

    while (n > 0) {
        char d = n % b;

        if (d < 10) {
            d += '0';
        } else {
            d += 'A' - 10;
        }

        r += d;
        n /= b;
    }

    reverse(r.begin(), r.end());

    return r;
}

bool is_pal(string n) {
    string pal = n;

    string left = pal.substr(0, pal.length() / 2);
    string right;

    if (pal.length() % 2) {
        right = pal.substr((pal.length() / 2) + 1);
    } else {
        right = pal.substr(pal.length() / 2);
    }

    reverse(right.begin(), right.end());

    return left == right;
}

bool is_dpal(string n) {
    int c = 0;

    for (int i = 2; i <= 10; i++) {
        if (is_pal(convert(stoi(n), i))) {
            c++;
        }

        if (c == 2) {
            return true;
        }
    }

    return false;
}

int main() {
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    fin >> n >> s;

    int c = 0;

    for (int i = s + 1; i <= INT_MAX; i++) {
        if (is_dpal(to_string(i))) {
            fout << i << "\n";
            c++;
        }

        if (c == n) {
            break;
        }
    }

    return 0;
}