/*
ID: lieugen1
TASK: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin ("ride.in");
    ofstream fout ("ride.out");

    string comet;
    int comet_value = 1;
    getline(fin, comet);

    for (int i = 0; i < comet.length(); i++) {
        comet_value *= comet[i] - 'A' + 1;
    }

    string group;
    int group_value = 1;
    getline(fin, group);

    for (int i = 0; i < group.length(); i++) {
        group_value *= group[i] - 'A' + 1;
    }

    if (comet_value % 47 == group_value % 47) {
        fout << "GO\n";
    } else {
        fout << "STAY\n";
    }

    return 0;
}