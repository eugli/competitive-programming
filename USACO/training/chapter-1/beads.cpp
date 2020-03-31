/*
ID: lieugen1
TASK: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin ("beads.in");
    ofstream fout ("beads.out");

    int beads;
    fin >> beads;

    string necklace;
    fin >> necklace;

    necklace = necklace + necklace;
    string red_necklace = necklace;
    string blue_necklace = necklace;

    int rleft = 0;
    int rright = 0;
    int bleft = 0;
    int bright = 0;
    int total = 0;
    int tmax = 0;

    for (int i = 1; i < necklace.length(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (necklace[j] == 'w') {
                red_necklace[j] = 'r';
                blue_necklace[j] = 'b';
            }
        }

        for (int j = i - 1; j >= 0; j--) {
            if (blue_necklace[j] == 'b') {
                bleft++;
            } else {
                break;
            }
        }

        for (int j = i - 1; j >= 0; j--) {
            if (red_necklace[j] == 'r') {
                rleft++;
            } else {
                break;
            }
        }

        cout << rleft << " " << bleft << endl;

        for (int k = i; k < necklace.length(); k++) {
            if (necklace[k] == 'w') {
                red_necklace[k] = 'r';
                blue_necklace[k] = 'b';
            }
        }

        cout << rright << " " << bright << endl;

        for (int k = i; k < necklace.length(); k++) {
            if (red_necklace[k] == 'r') {
                rright++;
            } else {
                break;
            }
        }

        for (int k = i; k < necklace.length(); k++) {
            if (blue_necklace[k] == 'b') {
                bright++;
            } else {
                break;
            }
        }

        cout << red_necklace << endl;
        cout << blue_necklace << endl;

        red_necklace = necklace;
        blue_necklace = necklace;

        total = max(max(rleft + rright, bleft + bright), max(rleft + bright, bleft + rright));
        rleft = 0;
        rright = 0;
        bleft = 0;
        bright = 0;

        if (total > tmax) {
            tmax = total;
        }
    }

    if (tmax > necklace.length() / 2) {
        tmax = necklace.length() / 2;
    }

    fout << tmax << endl;

    return 0;
}