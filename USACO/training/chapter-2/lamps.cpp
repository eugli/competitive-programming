/*
	ID: lieugen1
	TASK: lamps
	LANG: C++
*/

#include <bits/stdc++.h>

#define MAX 101

using namespace std;

int n, c, lamps_on[6], lamps_off[6];
string lps;

set<string> sols;
map<int, string> bits;

bitset<6> bt;
bitset<4> buttons;

bool valid() {
	for (int i = 0; i < 6; i++) {
		if (lamps_on[i] && !bt[5 - i]) return false;
		if (lamps_off[i] && bt[5 - i]) return false;
	}

	return true;
}

void op(int cs) {
	switch (cs) {
		case 0:
			bt.flip();
			break;
		case 1:
			for (int i = 1; i < 6; i += 2) {
				bt.flip(i);
			}
			break;
		case 2:
			for (int i = 0; i < 6; i += 2) {
				bt.flip(i);
			}
			break;
		case 3:
			bt.flip(2);
			bt.flip(5);
			break;
	}
}

int main() {
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int temp;

		cin >> temp;

		if (temp == -1) break;

		if (!(temp % 6)) lamps_on[5] = 1;
		else lamps_on[temp % 6 - 1] = 1;
	}
 
 	for (int i = 0; i < n; i++) {
		int temp;

		cin >> temp;

		if (temp == -1) break;

		if (!(temp % 6)) lamps_off[5] = 1;
		else lamps_off[temp % 6 - 1] = 1;
	}

	for (int i = 0; i < 16; i++) {
		bt.set();
		buttons = i;

		// cout << "buttons: " << buttons.to_string() << "\n";

		for (int j = 0; j < 4; j++) {
			if (buttons.count() > c) {
				continue;
			}

			if (buttons[j]) {
				// cout << "j: " << j << "\n";
				op(j);
			}
		}

		// cout << "lamps: " << bt.to_string() << "\n";

		if (valid()) {
			sols.insert(bt.to_string());
		}
	}

	if (sols.empty()) {
		cout << "IMPOSSIBLE\n";
	} else {
       int len = 0;
       string s;

       for (auto& i : sols) {
            len = 0;
            s = "";

            while (len <= n) {
                s += i;
                len += 6;
            }

        	cout << s.substr(0, n) << "\n";
        }
	}
		
	return 0;
}