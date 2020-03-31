/*
	ID: lieugen1
	TASK: hamming
	LANG: C++
*/

#include <bits/stdc++.h>

#define MAX 64

using namespace std;

int n, b, d, nums[64];

int hamming_distance(int a, int b) {
	bitset<8> bi(a ^ b);

	return bi.count();
}

int main() {
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);

	cin >> n >> b >> d;

	int c = 1;

	for (int i = 0; i < 1 << b; i++) {
		int valid = true;

		for (int j = 0; j < c; j++) {
			// cout << "hd " << i << "|" << nums[j] << "|" << hamming_distance(i, nums[j]) << "\n";
			if (hamming_distance(i, nums[j]) < d) {
				valid = false;
			}
		}

		if (valid) {
			nums[c] = i;
			c++;

			if (c == n) {
				goto finish;
			}
		}
	}

	finish:
		
	for (int i = 0; i < n; i++) {
		if (i && i % 10 == 0) {
			cout << "\n";
		} else if (i) {
			cout << " ";
		}

		cout << nums[i];
	}

	cout << "\n";

	return 0;
}