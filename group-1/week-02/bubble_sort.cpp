#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e3 + 10;
int a[MAXN];

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
		
		for (int j = 1; j <= n; j++) cout << a[j] << ' ';
		cout << endl;
	}
	return 0;
}
