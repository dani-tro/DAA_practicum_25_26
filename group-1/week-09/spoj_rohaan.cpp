#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 64;

int dist[MAXN][MAXN];

void solve(int test) {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dist[i][j];
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	int r, ans = 0; cin >> r;
	for (int i = 0; i < r; i++) {
		int a, b;
		cin >> a >> b;
		ans += dist[a][b];
	}
	cout << "Case #" << test << ": " << ans << endl;
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int t; cin >> t;
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}
