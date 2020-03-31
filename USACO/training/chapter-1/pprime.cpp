/*
	ID: lieugen1
	TASK: pprime
	LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int a, b;

bool is_prime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

void generate_pprimes(int num, int depth, int len) {
	if (depth == (len + 1) / 2) {
	    int tmp = num / 10;

	    while (tmp) {
	      num = num * 10 + tmp % 10;
	      tmp /= 10;
    	}

    	if (is_prime(num)) {
    		if (num >= a && num <= b) {
    			cout << num << "\n";
    		}
    	}

    	return;
    }

	if (depth == 0) {
    	for (int i = 1; i < 10; i += 2) {
      		generate_pprimes(i, depth + 1, len);
    	}
  	} else {
    	for (int i = 0; i < 10; i++) {
      		generate_pprimes(num * 10 + i, depth + 1, len);
    	}
 	}
}

int main() {
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);

	cin >> a >> b;

	if (a == 5 || a == 6) {
		cout << "5\n7\n11\n";
	} else if (a <= 7) {
		cout << "7\n11\n";
	} else if (a <= 11) {
		cout << "11\n";
	}

	for (int i = 3; i < 9; i += 2) {
		generate_pprimes(0, 0, i);
	}

	return 0;
}