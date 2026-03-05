#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 10;
int a[MAXN];

void heapify(int i, int n) {
	int lef = 2 * i + 1, ri = 2 * i + 2;
	
	if (lef >= n) return;
	if (ri >= n) {
		if (a[lef] > a[i]) swap(a[lef], a[i]);
		return;
	}
	
	if (a[i] >= a[lef] && a[i] >= a[ri]) return;
	 
	if (a[lef] > a[ri]) {
		swap(a[lef], a[i]);
		heapify(lef, n);
	} else {
		swap(a[ri], a[i]);
		heapify(ri, n);
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = n - 1; i >= 0; i--) heapify(i, n);
	
	for (int k = n - 1; k >= 0; k--) {
		swap(a[0], a[k]);
		heapify(0, k);
	}
	
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
	cout << endl;
	return 0;
}
