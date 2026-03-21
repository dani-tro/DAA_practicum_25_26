#include <bits/stdc++.h>
using namespace std;

long long n, f;
bool p(long long x) {
	return 2 * f + x - 1ll > 2ll * n / x || (2 * f + x - 1 == 2ll * n / x && (2ll * n) % x == 0);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> f;
	
	long long l, r, mid;
	l = 1; r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (p(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
