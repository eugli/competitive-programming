/*
	ID: lieugen1
	TASK: ariprog
	LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y;
} ans[10005];

int cnt, n, m;
int bisquare[125001], num[125001];
 
bool cmp(node p, node q) {
    if(p.y == q.y) return p.x < q.x;
    return p.y < q.y;
}

void dfs(int dth, int a, int b, int nn) {
    if(dth == n){
        ans[cnt].x = a;
        ans[cnt].y = b;
        cnt++;
        return;
    }

    int l = nn + b;

    if (bisquare[l]) {
    	dfs(++dth, a, b, l);
    } else {
    	return;
    }
}

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    cin >> n >> m;

    int k = 0;

    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= m; j++){
            if (!bisquare[i * i + j * j]) {
                bisquare[i * i + j * j] = 1;
                num[k++] = i * i  + j * j;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int mm = m * m * 2;

        for (int j = 1; j * (n - 1) <= mm; j++) {
            if ((j * (n - 1) + num[i]) <= mm)
            	dfs(1, num[i], j, num[i]);
        }
    }

    if (cnt == 0) {
    	cout << "NONE\n";
    } else {
        sort(ans, ans + cnt, cmp);
        for (int i = 0; i < cnt; i++){
        	cout << ans[i].x << " " << ans[i].y << "\n";
        }
    }
 
    return 0;
}