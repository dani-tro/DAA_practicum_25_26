#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
long long a[MAXN];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	long long k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int r = 1;
	long long sum = 0, ans = -1;
	for (int l = 1; l <= n; l++) {
		while (r <= n && sum + a[r] <= k) {
			sum += a[r];
			r++;
		}
		
		ans = max(ans, sum);
		sum -= a[l];
	}
	
	if (ans == 0) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
