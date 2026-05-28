#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

vector <int> v[MAXN];
int dp[MAXN][2];

void dfs(int x, int p) {
	int sum = 0, maxd = 0;
	for (auto i : v[x]) {
		if (i == p) continue;
		dfs(i, x);
		sum += dp[i][0];
		maxd = max(maxd, dp[i][1] - dp[i][0] + 1);
	}
	dp[x][1] = sum;
	dp[x][0] = sum + maxd;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, -1);
	cout << dp[1][0] << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
