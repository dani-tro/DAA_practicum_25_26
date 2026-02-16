#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
	int n; cin >> n;
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		sum += a;
	}
	
	cout << sum << endl;
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
}
