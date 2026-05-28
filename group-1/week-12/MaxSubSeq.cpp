#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 10;

int dp[MAXN][MAXN];

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				dp[i][i] = (s[i - 1] == t[j - 1]);
				continue;
			}
			
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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
