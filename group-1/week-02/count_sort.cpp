#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXA = 1e3 + 10;
const int MAXN = 3e6 + 10;
int cnt[MAXA];
short a[MAXN];

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < cnt[i]; j++) cout << i << ' ';
	}
	cout << endl;
	return 0;
}
