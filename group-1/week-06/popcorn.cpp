#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5 + 10;
int a[MAXN];
int n, k, s;

bool p(int x) {
	x = x * s;
	int curC = 0;
	int people = 1;
	
	for (int i = 1; i <= n; i++) {
		if (a[i] > x) return false;
		
		if (curC + a[i] > x) {
			curC = 0;
			people++;
		}
		curC += a[i];
	}
	
	return people <= k;
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k >> s;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	
	int l = 1, r = sum;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (p(mid)) r = mid - 1;
		else l = mid + 1;
	}
	
	cout << l << endl;
	return 0;
}
/*
5 3 4
5 8 3 10 7

3 2 1
1 5 1
*/
