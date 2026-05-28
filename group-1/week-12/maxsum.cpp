#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 10;
const int MAXK = 1e3 + 10;

const int INF = 1e18;

int a[MAXN], h[MAXK];
int dpL[MAXN], dpR[MAXN], maxL[MAXN];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= k; i++) cin >> h[i];
	
	dpL[1] = maxL[1] = a[1]; dpR[n] = a[n];
	for (int i = 2; i <= n; i++) {
		dpL[i] = -INF;
		for (int j = 1; j <= k; j++) {
			if (i - h[j] >= 1 && dpL[i - h[j]] != -INF) dpL[i] = max(dpL[i], dpL[i - h[j]] + a[i]);	
		}
		maxL[i] = maxL[i - 1];
		if (dpL[i] == -INF) continue;
		maxL[i] = max(maxL[i], dpL[i]);
	}
	
	int ans = dpR[n] + maxL[n - 1];
	for (int i = n - 1; i >= 2; i--) {
		dpR[i] = -INF;
		for (int j = 1; j <= k; j++) {
			if (i + h[j] <= n && dpR[i + h[j]] != -INF) dpR[i] = max(dpR[i], dpR[i + h[j]] + a[i]);	
		}
		if (dpR[i] == -INF) continue;
		ans = max(ans, dpR[i] + maxL[i - 1]);
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
/*
9 2
3 2 6 6 0 2 4 5 5
3 2

6 2
1 4 7 2 5 1
3 4
*/
