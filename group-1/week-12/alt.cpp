#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100;
const int MAXM = 100;

int dp[MAXN][MAXM];

void solve() {
	int n, m, k;
	cin >> k >> m >> n;
	m--;
	for (int i = 1; i <= m; i++) dp[1][i] = 1;
	
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = (j + k <= m ? dp[i - 1][j + k] : 0) + (j - k >= 1 ? dp[i - 1][j - k] : 0);
			if (i == n) ans += dp[i][j];
		}
	}
	cout << ans << endl;
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
