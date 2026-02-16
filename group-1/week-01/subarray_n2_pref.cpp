#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e4 + 10;

int a[MAXN], pref[MAXN];

void solve () {
	int n; cin >> n;
	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	
	int ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r += 2) {
			ans += pref[r] - pref[l - 1];
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
