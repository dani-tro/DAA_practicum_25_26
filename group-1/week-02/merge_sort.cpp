#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e3 + 10;
int a[MAXN], b[MAXN], maxLev;
int ans[16][MAXN];

void merge_sort(int l, int r, int lev) {
	maxLev = max(maxLev, lev);
	if (l == r) {
		ans[lev][l] = a[l];
		return;
	}
	
	int mid = (l + r) / 2;
	merge_sort(l, mid, lev + 1);
	merge_sort(mid + 1, r, lev + 1);
	
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) {
			b[k] = a[i];
			k++;
			i++;
		} else {
			b[k] = a[j];
			k++; j++;
		}
	}
	
	while (i <= mid) {
		b[k] = a[i];
		i++; k++;
	}
	while (j <= r) {
		b[k] = a[j];
		k++; j++;
	}
	
	for (int i = l; i <= r; i++) {
		a[i] = b[i];
		ans[lev][i] = b[i];	
	}
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	merge_sort(1, n, 0);
	
	for (int i = 0; i <= maxLev; i++) {
		for (int j = 1; j <= n; j++) cout << ans[i][j] << ' ';
		cout << endl;
	}
}
