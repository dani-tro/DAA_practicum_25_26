#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const long long mod = 1e9 + 7;
const int MAXN = 2e2 + 10;
const int MAXS = 5e4 + 10;

int a[MAXN], b[MAXN];
long long dp[2][MAXS];

long long getSum(int idx, int s1, int s2, int el) {
	long long res = 0;
	for (int i = s1; i <= s2; i += el) res = (res + dp[idx][i]) % mod;
	return res;
}

void solve() {
	int s, n;
	cin >> s >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	dp[0][0] = 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			int m = min(b[i], j / a[i]);
			dp[i % 2][j] = getSum(((i & 1) ^ 1), j - a[i] * m, j, a[i]);
			
			/*if (i <= n - 1) {
				if (j < a[i + 1]) pref[i % 2][j] = cur;
				else pref[i % 2][j] = (pref[i % 2][j - a[i + 1]] + cur) % mod;
			} else if (j == s) ans = cur;*/
		}
	}
	cout << dp[n % 2][s] << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
}
