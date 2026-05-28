#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

vector <int> v[MAXN];
int dp[MAXN][2];

void dfs(int x, int p) {
	vector <int> ch;
	ch.push_back(-1);
	dp[x][1] = 0;
	for (auto i : v[x]) {
		if (i == p) continue;
		dfs(i, x);
		ch.push_back(i);
		dp[x][1] += dp[i][0];
	}
	
	int k = ch.size() - 1;
	vector <int> pref(k + 1), suf(k + 2);
	pref[0] = suf[k + 1] = 0;
	
	for (int i = 1; i <= k; i++) pref[i] = pref[i - 1] + dp[ch[i]][0];
	for (int i = k; i >= k; i--) suf[i] = suf[i + 1] + dp[ch[i]][0];
	
	dp[x][0] = 0;
	for (int i = 1; i <= k; i++) {
		dp[x][0] = max(dp[x][0], pref[i - 1] + suf[i + 1] + dp[ch[i]][1]);
	}
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
