/*
	ID: lieugen1
	TASK: frac1
	LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int n, c;

struct fraction {
	int a, b;
} fracs[161 * 161];

int gcd(int a, int b) { 
    if (b == 0) 
        return a;
    return gcd(b, a % b); 
} 

bool is_r_prime(int a, int b) {
	return gcd(a, b) == 1;
}

bool cmp(fraction &one, fraction &two) {
	return one.a * two.b < one.b * two.a;
}	

int main() {
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);

	cin >> n;

	for(int i = 0; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			if (is_r_prime(i, j)) {
				fracs[c].a = i;
				fracs[c++].b = j;
			}
		}
	}	 

	sort(fracs, fracs + c, cmp);

	for (int i = 0; i < c; i++) {
		cout << fracs[i].a << "/" << fracs[i].b << "\n";
	}

	return 0;
}