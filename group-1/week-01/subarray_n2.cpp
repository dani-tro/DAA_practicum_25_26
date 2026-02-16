#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e4 + 10;

int a[MAXN];

void solve () {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = 0;
	for (int l = 1; l <= n; l++) {
		int sum = 0;
		for (int r = l; r <= n; r++) {
			sum += a[r];
			if ((r - l + 1) % 2) ans += sum;
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
