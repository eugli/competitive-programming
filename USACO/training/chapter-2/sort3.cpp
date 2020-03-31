/*
	ID: lieugen1
	TASK: sort3
	LANG: C++
*/

#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int n, s, nums[MAX], copy_arr[MAX];

int main() {
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		copy_arr[i] = nums[i];
	}

	sort(copy_arr, copy_arr + n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n && j != i; j++) {
			if (nums[i] != copy_arr[i] && nums[j] != copy_arr[j] &&
				nums[i] == copy_arr[j] && nums[j] == copy_arr[i]) {
				nums[i] = copy_arr[i];
				nums[j] = copy_arr[j];
				s++;
			}
		}
	}

	int rem = 0;

	for (int i = 0; i <  n; i++) {
		if (nums[i] != copy_arr[i]) {
			rem++;
		}
	}

	cout << s + 2 * rem / 3 << "\n";

	return 0;
}