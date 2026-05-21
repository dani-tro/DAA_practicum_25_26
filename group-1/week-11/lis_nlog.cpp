#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
const int INF = INT_MAX;

int a[MAXN], dp[MAXN];

void solve () {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = INF;	
	}
	dp[0] = -INF;
	
	for (int i = 1; i <= n; i++) {
		int l, r, mid;
		l = 0; r = i - 1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (dp[mid] <= a[i]) l = mid + 1;
			else r = mid - 1;
		}
		dp[l] = a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		if (dp[i + 1] == INF) {
			cout << i << endl;
			break;
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
