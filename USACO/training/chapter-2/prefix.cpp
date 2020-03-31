/*
	ID: lieugen1
	TASK: prefix
	LANG: C++
*/

#include <bits/stdc++.h>
	
#define MAX 200
#define MAXL 200000

using namespace std;

string primitives[MAX], sequence;

int main() {
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);

	int c = 0;

	while (true) {
		string temp;
		cin >> temp;

		if (temp == ".") break;

		primitives[c++] = temp;
	}

	while (true) {
		string temp;
		cin >> temp;

		if (temp == "") break;

		sequence += temp;
	}

	int dp[sequence.length() + 1] = {0};
	dp[0] = 1;
	int max = 0;

	for (int i = 0; i <= sequence.length(); i++) {
		for (int j = 0; j < c; j++) {
			int s = i - primitives[j].length();
			if (s < 0) continue;
			if (sequence.substr(s, primitives[j].length()) != primitives[j]) continue;
			if (!dp[s]) continue;

			dp[i] = 1;
			max = i;
			break;
		}
	}

	cout << max << "\n";

	return 0;
}