/*
	ID: lieugen1
	TASK: preface
	LANG: C++
*/

#include <bits/stdc++.h>

#define MAX

using namespace std;

int n, vals[7];
string names[7] = {"I", "V", "X", "L", "C", "D", "M"};

enum roman {
	I = 1,
	IV = 4,
	V = 5,
	IX = 9,
	X = 10,
	XL = 40,
	L = 50,
	XC = 90,
	C = 100,
	CD = 400,
	D = 500,
	CM = 900,
	M = 1000
};

void solve(int num) {
	vals[6] += num / M;
	num %= M;

	vals[6] += num / CM;
	vals[4] += num / CM;
	num %= CM;

	vals[5] += num / D;
	num %= D;

	vals[5] += num / CD;
	vals[4] += num / CD;
	num %= CD;

	vals[4] += num / C;
	num %= C;

	vals[4] += num / XC;
	vals[2] += num / XC;
	num %= XC;

	vals[3] += num / L;
	num %= L;

	vals[3] += num / XL;
	vals[2] += num / XL;
	num %= XL;

	vals[2] += num / X;
	num %= X;

	vals[0] += num / IX;
	vals[2] += num / IX;
	num %= IX;

	vals[1] += num / V;
	num %= V;

	vals[0] += num / IV;
	vals[1] += num / IV;
	num %= IV;

	vals[0] += num / I;
}

int main() {
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		solve(i);
	}

	for (int i = 0; i < 7; i++) {
		if (vals[i]) {
			cout << names[i] << " " << vals[i] << "\n";
		}
	}

	return 0;
}