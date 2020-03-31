/*
	ID: lieugen1
	TASK: sprime
	LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int n;

bool is_prime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

void generate_sprimes(int num, int s) {
	if (s == n) {
		cout << num << "\n";
	}

	if (s == 0) {
		for (int i = 2; i <= 7; i++) {
			if (i == 2 || i % 2 == 1) {
				generate_sprimes(i, s + 1);
			}
		}
	} else {
		for (int i = 1; i <= 9; i+=2) {
			int temp = num * 10 + i; 

			if (is_prime(temp)) {
				generate_sprimes(temp, s + 1);
			}
		}
	}
}

int main() {
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);

	cin >> n;

	generate_sprimes(0, 0);
		
	return 0;
}