/*
	ID: lieugen1
	TASK: skidesign
	LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int n, c, ski[1001];

int main() {
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);

	cin >> n;

	int a = INT_MAX;

	for (int i = 0; i < n; i++) {
		cin >> ski[i];
	}

	for (int i = 0; i <= 83; i++) {
		for (int j = 0; j < n; j++) {
			if (ski[j] < i) {
				c += pow(i - ski[j], 2);
			} else if (ski[j] > i + 17) {
				c += pow(ski[j] - i - 17, 2);
			}
		}

		a = min(a, c);
		c = 0;
	}

	cout << a << "\n";
	
	return 0;
}