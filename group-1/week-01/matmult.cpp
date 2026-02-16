#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[32][32], b[32][32], c[32][32];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int p = 0; p < m; p++) {
				c[i][j] += a[i][p] * b[p][j];
			}
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
