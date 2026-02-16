#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int cnt = 0;
		
		while (x > 0) {
			cnt += (x & 1);
			x = (x >> 1);
		}
		
		cout << cnt << endl;
	}
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
