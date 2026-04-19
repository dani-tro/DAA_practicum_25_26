#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 3e5 + 10;
int a[MAXN];

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, d; cin >> n >> d;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int r = 0, ans = 0;
	for (int l = 0; l < n; l++) {
		while (r < n && a[r] - a[l] <= d) r++;
		ans += n - r;
	}
	cout << ans << endl;
	return 0;
}
