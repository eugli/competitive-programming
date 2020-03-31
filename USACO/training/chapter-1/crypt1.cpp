/*
	ID: lieugen1
	TASK: crypt1
	LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int n, sol;
map<int, bool> in;
vector<int> nums;

bool valid(int num) {
	string str = to_string(num);

	for (int i = 0; i < str.length(); i++) {
		if (!in[str[i] - '0']) {
			return false;
		}
	}

	return true;
}

int main() {
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);

	cin >> n;

	nums.resize(n);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		in[a] = true;
		nums[i] = a;
	}

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	for (int k = 0; k < n; k++)
	for (int l = 0; l < n; l++)
	for (int m = 0; m < n; m++) {
		int one = 100 * nums[i] + 10 * nums[j] + nums[k];
		int two = 10 * nums[l] + nums[m];

		int three = nums[m] * one;
		int four = nums[l] * one;

		int five = three + four * 10;

		if (three < 1000 &&
			four < 1000 &&
			five < 10000 &&
			valid(three) &&
			valid(four) &&
			valid(five)) {
			sol++;
		}
	}

	cout << sol << "\n";
	
	return 0;
}