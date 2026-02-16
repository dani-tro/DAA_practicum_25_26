#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve () {
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		ans += (i / 2 * (n / 2 - (i - 1) / 2) + (i + 1) / 2 * ((n + 1) / 2 - i / 2) ) * a;
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
