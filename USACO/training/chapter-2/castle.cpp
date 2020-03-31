/*
	ID: lieugen1
	TASK: castle
	LANG: C++
*/

#include <bits/stdc++.h>

#define MAX 50

using namespace std;

int m, n, component, castle[MAX][MAX], visited[MAX][MAX], comp[MAX * MAX + 1];

void flood_fill(int i, int j) {
	if (visited[i][j] == -2) {
		visited[i][j] = component;
		comp[component]++;
	}

	if (i < n - 1 && !(castle[i][j] & 8)) {
		if (!visited[i + 1][j]) {
			visited[i + 1][j] = -2;
			flood_fill(i + 1, j);
		}
	}

	if (j < m - 1 && !(castle[i][j] & 4)) {
		if (!visited[i][j + 1]) {
			visited[i][j + 1] = -2;
			flood_fill(i, j + 1);
		}
	}

	if (i > 0 && !(castle[i][j] & 2)) {
		if (!visited[i - 1][j]) {
			visited[i - 1][j] = -2;
			flood_fill(i - 1, j);
		}
	}	

	if (j > 0 && !(castle[i][j] & 1)) {
		if (!visited[i][j - 1]) {
			visited[i][j - 1] = -2;
			flood_fill(i, j - 1);
		}
	}
}

int main() {
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> castle[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				component++;
				visited[i][j] = -2;
				flood_fill(i, j);
			}
		}
	}

	int ma = 0;

	for (int i = 0; i < m * n + 1; i++) {
		if (comp[i] > ma) {
			ma = comp[i];
		}
	}

	cout << component << "\n";
	cout << ma << "\n";

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << visited[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	int nma, nmx, nmy;
	char nmd;
	nma = nmx = nmy = 0;

	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (i > 0 && visited[i][j] != visited[i - 1][j]) {
				int temp = comp[visited[i][j]] + comp[visited[i - 1][j]];
				
				if (temp > nma) {
					nma = temp;
					nmy = i + 1;
					nmx = j + 1;
					nmd = 'N';
				}
			}

			if (j < m - 1 && visited[i][j] != visited[i][j + 1]) {
				int temp = comp[visited[i][j]] + comp[visited[i][j + 1]];
				
				if (temp > nma) {
					nma = temp;
					nmy = i + 1;
					nmx = j + 1;
					nmd = 'E';
				}
			}
		}
	}

	cout << nma << "\n";
	cout << nmy << " " << nmx << " " << nmd << "\n";

	return 0;
}