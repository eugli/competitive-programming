/*
	ID: lieugen1
	TASK: milk3
	LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int a_cap, b_cap, c_cap, milk[21], visited[21][21][21];

struct state {
    int a, b, c, n;
};

queue<state> q;

bool is_valid(int a, int b, int c) {
    return (a >= 0 && a <= a_cap) &&
           (b >= 0 && b <= b_cap) &&
           (c >= 0 && c <= c_cap);
}

void process(state s) {
    // cout << s.a << " " << s.b << " " << s.c << endl;

    if (s.a == 0 && !milk[s.c]) {
        milk[s.c] = 1;
    }

    if (is_valid(a_cap, s.b, s.c + s.a - a_cap) && !visited[a_cap][s.b][s.c + s.a - a_cap]) {
        q.push(state{a_cap, s.b, s.c + s.a - a_cap});
    }

    if (is_valid(s.a + s.c, s.b, 0) && !visited[s.a + s.c][s.b][0]) {
        q.push(state{s.a + s.c, s.b, 0}); 
    }

    if (is_valid(s.a, b_cap, s.c + s.b - b_cap) && !visited[s.a][b_cap][s.c + s.b - b_cap]) {
        q.push(state{s.a, b_cap, s.c + s.b - b_cap}); 
    }

    if (is_valid(s.a, s.b + s.c, 0) && !visited[s.a][s.b + s.c][0]) {
        q.push(state{s.a, s.b + s.c, 0}); 
    }

    if (is_valid(s.a + s.b - b_cap, b_cap, s.c) && !visited[s.a + s.b - b_cap][b_cap][s.c]) {
        q.push(state{s.a + s.b - b_cap, b_cap, s.c});
    }

    if (is_valid(0, s.b + s.a, s.c) && !visited[0][s.b + s.a][s.c]) {
        q.push(state{0, s.b + s.a, s.c}); 
    }

    if (is_valid(s.a + s.c - c_cap, s.b, c_cap) && !visited[s.a + s.c - c_cap][s.b][c_cap]) {
        q.push(state{s.a + s.c - c_cap, s.b, c_cap});
    }

    if (is_valid(0, s.b, s.c + s.a) && !visited[0][s.b][s.c + s.a]) {
        q.push(state{0, s.b, s.c + s.a}); 
    }

    if (is_valid(a_cap, s.b + s.a - a_cap, s.c) && !visited[a_cap][s.b + s.a - a_cap][s.c]) {
        q.push(state{a_cap, s.b + s.a - a_cap, s.c});
    }

    if (is_valid(s.a + s.b, 0, s.c) && !visited[s.a + s.b][0][s.c]) {
        q.push(state{s.a + s.b, 0, s.c}); 
    }

    if (is_valid(s.a, s.b + s.c - c_cap, c_cap) && !visited[s.a][s.b + s.c - c_cap][c_cap]) {
        q.push(state{s.a, s.b + s.c - c_cap, c_cap});
    }

    if (is_valid(s.a, 0, s.c + s.b) && !visited[s.a][0][s.c + s.b]) {
        q.push(state{s.a, 0, s.c + s.b}); 
    }
}

int main() {
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);

	cin >> a_cap >> b_cap >> c_cap;

    q.push(state {0, 0, c_cap, 0});

    while (!q.empty()) {
        state s = q.back();
        visited[s.a][s.b][s.c] = 1;

        q.pop();
        process(s);
    }

    for (int i = 0; i < 21; i++) {
        if (milk[i]) {
            if (i != c_cap) {
                cout << i << " ";
            } else {
                cout << i;
            }
        }
    }

    cout << "\n";

	return 0;
}