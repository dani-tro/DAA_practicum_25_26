#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e6 + 10;
int a[MAXN], b[MAXN];

int solve(int l, int r) {
	if (l == r) return 0;
	int mid = (l + r) / 2;
	int ans = solve(l, mid) + solve(mid + 1, r);
	
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) {
			ans += j - mid - 1; // j - 1 - (mid + 1) + 1
			b[k] = a[i];
			k++;
			i++;
		} else {
			b[k] = a[j];
			k++; j++;
		}
	}
	
	while (i <= mid) {
		ans += r - mid; // броят на елементите от mid+1 до r включително
		b[k] = a[i];
		i++; k++;
	}
	while (j <= r) {
		b[k] = a[j];
		k++; j++;
	}
	
	for (int i = l; i <= r; i++) a[i] = b[i];
	return ans;
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	cout << solve(1, n) << endl;
}
