#include <bits/stdc++.h>
using namespace std;

const int MAXN = 64;
const int MAXW = 5e4 + 10;
const int INF = 1e9;

int dp[2][MAXW], a[MAXN];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < MAXW; i++) dp[0][i] = -1;
	
	int i0 = 0, i1 = 1; // винаги смятаме от i0 -> i1
	for (int i = 1; i <= n; i++) {
		for (int b = 0; b < MAXW; b++) {
			int cur = INF;
			if (b + a[i] < MAXW && dp[i0][b + a[i]] != -1) {
				cur = min(cur, dp[i0][b + a[i]]);
			}
			if (dp[i0][abs(b - a[i])] != -1) {
				cur = min(cur, dp[i0][abs(b - a[i])]);
			}
			if (dp[i0][b] != -1) cur = min(cur, dp[i0][b] + a[i]);
			if (cur == INF) dp[i1][b] = -1;
			else dp[i1][b] = cur;
		}
		swap(i0, i1);
	}
	
	cout << dp[i0][0] << endl;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
