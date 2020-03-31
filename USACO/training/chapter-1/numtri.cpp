/*
	ID: lieugen1
	TASK: numtri
	LANG: C++
*/

#include <bits/stdc++.h>
 
using namespace std;

int r, k, m, tri[1001][1001], dp[1001][1001];

// void dfs(int i, int j, int end, int sum) {
// 	if (i > end) {
// 		m = max(m, sum);
// 	} else {
// 		sum += tri[i][j];
// 		dfs(i + 1, j, end, sum);
// 		dfs(i + 1, j + 1, end, sum);
// 	}
// }

int main() {
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);

	cin >> r;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j <= k; j++) {
			cin >> tri[i][j];
		}

		k++;
	}

	for (int i = 0; i < r; i++) {
		dp[r - 1][i] = tri[r - 1][i];
	}

	for (int i = r - 2; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			dp[i][j] = max(dp[i + 1][j] + tri[i][j], dp[i + 1][j + 1] + tri[i][j]); 
		}
	}

	// for (int i = 0; i < r; i++) {
	// 	for (int j = 0; j <= k; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}

	// 	cout << endl;
	// }

	cout << dp[0][0] << "\n";
	
	return 0;
} 