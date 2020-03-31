/*
	ID: lieugen1
	TASK: wormhole
	LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int n, x[13], y[13], partner[13], next_on_right[13];

bool is_solved() {
	for (int i = 1; i <= n; i++) {
		int pos = i;

		for (int j = 1; j <= n; j++) {
			pos = next_on_right[partner[pos]];
		}

		if (pos != 0) return true;
	}

	// for (int i = 1; i <= n; i++) {
	// 	cout << partner[i] << " " << endl;
	// }
	
	return false;
}

int generate_pairs() {
	int i = 0, s = 0;

	for (i = 1; i <= n; i++) {
		if (partner[i] == 0) break;
	}

	if (i > n) {
		return (is_solved()) ? 1 : 0;
	}

	for (int j = i + 1; j <= n; j++) {
		if (partner[j] == 0) {
			partner[i] = j;
			partner[j] = i;
			s += generate_pairs();
			partner[i] = partner[j] = 0;
		}
	}

	return s;
}

int main() {
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[j] > x[i] && y[i] == y[j]) {
				if (next_on_right[i] == 0 ||
					x[j] < x[next_on_right[i]]) {
					next_on_right[i] = j;
				}
			}
		}
	}

	cout << generate_pairs() << "\n";

	return 0;
}
