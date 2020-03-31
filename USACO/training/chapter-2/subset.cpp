/*
	ID: lieugen1
	TASK: subset
	LANG: C++
*/

#include <bits/stdc++.h>

#define MAX 40

using namespace std;

long long int n, nums[MAX], buckets[MAX][MAX * (MAX + 1) / 2];

int main() {
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);

	cin >> n;

	int m = n * (n + 1) / 2;

	if (m % 2) {
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i <= n; i++) {
		buckets[i][0] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			buckets[i][j] = buckets[i - 1][j];
		}

		for (int j = 0; j <= m; j++) {
			buckets[i][j + i] += buckets[i - 1][j];
		}
	}

	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= m; j++) {
	// 		cout << buckets[i][j] << " ";
	// 	}

	// 	cout << "\n";
	// }

	cout << buckets[n][m / 2] / 2 << "\n";
	
	return 0;
}