/*
	ID: lieugen1
	TASK: combo
	LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int n, one[3], two[3], combo[3], c;

bool valid_one (int * combo) {
	for (int i = 0; i < 3; i++) {
		if (abs(combo[i] - one[i]) > 2 && n - abs(combo[i] - one[i]) > 2) {
			return false;
		}
	}

	return true;
}

bool valid_two (int * combo) {
	for (int i = 0; i < 3; i++) {
		if (abs(combo[i] - two[i]) > 2 && n - abs(combo[i] - two[i]) > 2) {
			return false;
		}
	}

	return true;
}


int main() {
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < 3; i++) {
		cin >> one[i];
	}

	for (int j = 0; j < 3; j++) {
		cin >> two[j];
	}

	for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= n; j++)
	for (int k = 1; k <= n; k++) {
		combo[0] = i;
		combo[1] = j;
		combo[2] = k;

		if (valid_one(combo) || valid_two(combo)) {
			c++;
		}
	}
	
	cout << c << "\n";
	
	return 0;
}