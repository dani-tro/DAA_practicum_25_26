#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a, a + n); sort(b, b + m);
	
	int ans = 0, r = 0;
	for (int l = 0; l < n; l++) {
		while (r < m && a[l] > b[r]) r++;
		if (r == m) break;
		ans++;
		r++;
	}
	
	cout << ans << endl;
	return 0;
}
