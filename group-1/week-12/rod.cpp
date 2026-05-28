#include <bits/stdc++.h>
using namespace std;

const int MAXN = 512;
const int INF = 1e9;

int a[MAXN], dp[MAXN][MAXN];
int pref[MAXN];

void solve() {
	int n; cin >> n;
	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	
	for (int l = 1; l <= n; l++) dp[l][l + 1] = a[l]; //base
	
	for (int d = 2; d <= n; d++) {
		for (int l = 1; l + d <= n + 1; l++) {
			int r = l + d;
			
			dp[l][r] = INF;
			for (int i = l + 1; i < r; i++) {
				dp[l][r] = min(dp[l][r], dp[l][i] + dp[i][r]);
			}
			dp[l][r] += pref[r - 1] - pref[l - 1];
			//cout << l << ' ' << r << ' ' << dp[l][r] << endl;
		}
	}
	cout << dp[1][n + 1] - pref[n] << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
