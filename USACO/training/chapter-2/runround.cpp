/*
	ID: lieugen1
	TASK: runround
	LANG: C++
*/

#include <bits/stdc++.h>

#define MAX

using namespace std;

int n;

bool is_runaround(long int m) {
	string convert = to_string(m);
	int len = convert.length();

	bool visited[10] = {0};

	for (int i = 0; i < len; i++) {
		if (visited[convert[i] - '0']) {
			return false;
		}

		visited[convert[i] - '0'] = 1;
	}

	int j = 0;
	char start = convert[j];

	bool visited_two[10] = {0};
	visited_two[start - '0'] = 1;

	// cout << m << "\n";

	for (int i = 0; i < len; i++) {
		j = (j + start - '0') % len;
		start = convert[j];

		// cout << start << " ";

		if (i != len - 1 && visited_two[start - '0']) {
			return false;
		}

		visited_two[start - '0'] = 1;
	}

	// cout << "\n-------------\n";

	return start == convert[0];
}

int main() {
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);

	cin >> n;

	for (long int i = n + 1; ; i++) {
		if (is_runaround(i)) {
			cout << i << "\n";
			return 0;
		}

		// if (i == 200) {
		// 	break;
		// }
	}
		
	return 0;
}