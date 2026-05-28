#include <bits/stdc++.h>
using namespace std;

const int MAXN = 512;
long long dp[MAXN][MAXN];

void solve() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) dp[0][i] = 1;
	for (int s = 1; s <= n; s++) {
		for (int g = 1; g <= m; g++) {
			for (int i = 1; i <= min(g, s); i++) {
				dp[s][g] += dp[s - i][i];
			}
		}
	}
	
	cout << dp[n][m] << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
