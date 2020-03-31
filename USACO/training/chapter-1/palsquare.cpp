/*
ID: lieugen1
TASK: palsquare
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int b;
string pal;

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

string convert(int n) {
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

string find_sq(int n) {
    int square = pow(n , 2);

    return convert(square);
}

int main() {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    fin >> b;

    for (int i = 1; i <= 300; i++) {
        pal = find_sq(i);

        if (is_pal(pal)) {
            fout << convert(i) << " " << pal << "\n";
        }
    }

    return 0;
}