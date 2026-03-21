#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;

int n, k;
int a[MAXN];

bool check(int x) {
	multiset <int> ms;
	for (int i = 1; i <= n; i++) ms.insert(a[i]);
	
	for (int i = 1; i <= k; i++) {
		int c = 0;
		while (true) {
			auto it = ms.upper_bound(x - c);
			if (it == ms.begin()) break;
			it--;
			
			c += *it;
			ms.erase(it);
		}
	}
	
	return ms.empty();
}

void solve() {
	cin >> n >> k;
	int sum = 0, mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		mx = max(a[i], mx);
	}
	
	int l, r, mid;
	l = mx; r = sum;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	
	cout << l << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
