/*
	ID: lieugen1
	TASK: holstein
	LANG: C++
*/

#include <bits/stdc++.h>

#define MAX1 25
#define MAX2 15

using namespace std;

int v, vitamins[MAX1], g, feed[MAX2][MAX1], mi;
string bit_rep, sol;

int num_feed(string s) {
	int ones = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			ones++;
		}
	}

	return ones;
}

bool is_satisfied(int* temp) {
	for (int i = 0; i < v; i++) {
		if (temp[i] < vitamins[i]) {
			return false;
		}
	}

	return true;
}

void solve(string bit_rep) {
	int temp[v] = {0};

	for (int i = 0; i < g; i++) {
		if (bit_rep[i] == '1') {
			for (int j = 0; j < v; j++) {
				temp[j] += feed[i][j];
			}
		}

		// for (int i = 0; i < v; i++) {
		// 	cout << temp[i] << " ";
		// }

		// cout << "\n";
	}

	int nfeed = num_feed(bit_rep);

	// cout << "feed: " << nfeed << "\n";

	if (is_satisfied(temp)) {
		if (nfeed < mi) {
			mi = nfeed;
			sol = bit_rep;
		} else if (nfeed == mi) {
			int sum_one = 0;
			int sum_two = 0;

			for (int i = 0; i < v; i++) {
				if (sol[i] == '1') {
					sum_one += i;
				}

				if (bit_rep[i] == '1') {
					sum_two += i;
				}
			}

			if (sum_two < sum_one) {
				sol = bit_rep;
			}
		}
	}
}

int main() {
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);

	cin >> v;

	for (int i = 0; i < v; i++) {
		cin >> vitamins[i];
	}

	cin >> g;

	for (int i = 0; i < g; i++) {
		for (int j = 0; j < v; j++) {
			cin >> feed[i][j];
		}
	}

	// for (int i = 0; i < g; i++) {
	// 	for (int j = 0; j < v; j++) {
	// 		cout << feed[i][j] << "  ";
	// 	}

	// 	cout << "\n";
	// }

	mi = INT_MAX;

	for (int i = 0; i < g; i++) {
		bit_rep += "0";
	}

	for (int i = 0; i < pow(2, g) - 1; i++) {
		int pos = bit_rep.length() - 1;

		while(bit_rep[pos] == '1') {
			bit_rep[pos] = '0';
			pos--;
		}

		bit_rep[pos] += 1;

		solve(bit_rep);
	}

	cout << mi << " ";

	int c = 0;

	for (int i = 0; i < g; i++) {
		if (sol[i] == '1') {
			cout << i + 1;
			c++;
			if (c != mi) cout << " ";
		}
	}

	cout << "\n";

	return 0;
}