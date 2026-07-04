#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const long long mod = 1e9 + 7;
const int MAXN = 2e2 + 10;
const int MAXS = 5e4 + 10;

int a[MAXN], b[MAXN];
long long pref[2][MAXS];

long long getSum(int idx, int s1, int s2, int el) {
	if (s1 < el) return pref[idx][s2];
	return (pref[idx][s2] - pref[idx][s1 - el] + mod) % mod;
}

void solve() {
	int s, n;
	cin >> s >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	for (int i = 0; i <= s; i++) pref[0][i] = (i % a[1] == 0);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			int m = min(b[i], j / a[i]);
			long long cur = getSum(((i & 1) ^ 1), j - a[i] * m, j, a[i]);
			
			if (i <= n - 1) {
				if (j < a[i + 1]) pref[i % 2][j] = cur;
				else pref[i % 2][j] = (pref[i % 2][j - a[i + 1]] + cur) % mod;
			} else if (j == s) ans = cur;
		}
	}
	cout << ans << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
}
