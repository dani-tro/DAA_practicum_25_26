#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e4 + 10;
int a[MAXN];

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int whiteLeft = i / 2 + 1;
		int blackLeft = (i + 1) - whiteLeft;
		bool isWhite = (i % 2 == 0);
		int whiteRight = (n - 1) / 2 + 1 - whiteLeft + isWhite;
		int blackRight = (n - i) - whiteRight;
		
		ans += a[i] * (whiteRight * whiteLeft + blackRight * blackLeft);
	}
	cout << ans << endl;
	return 0;
}
