#include <bits/stdc++.h>
using namespace std;

const int MAXN = 512;
long long dp[MAXN][MAXN];
bool mem[MAXN][MAXN];

long long rec(int s, int x) {
	if (mem[s][x]) return dp[s][x];
	mem[s][x] = true;
	
	if (s < x) return dp[s][x] = 0;
	if (s == x) return dp[s][x] = 1;
	
	for (int i = 1; i <= min(s, x); i++) {
		dp[s][x] += rec(s - x, i);
	}
	return dp[s][x];
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	long long ans = 0;
	for (int i = 1; i <= m; i++) ans += rec(n, i);
	cout << ans << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
