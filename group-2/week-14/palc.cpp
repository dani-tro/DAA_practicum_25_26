# include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
long long dp[maxn][maxn];
const int MOD = 1e9+7;
int main()
{
	// cout << ((-5)%3) << endl;
	string s;
	cin >> s;
	int n = s.size();

	for (int l = 0; l < n; l++)
	{
		for (int i = 0; i < n - l; i++)
		{
			int j = i + l;
			if (i == j) dp[i][j] = 1;
			else if (j == i+1) dp[i][j] = 2 + (s[i]==s[j]);
			else
				dp[i][j] = -dp[i+1][j-1] + dp[i][j-1] +
							dp[i+1][j] + ((int)s[i]==s[j])*(dp[i+1][j-1]+1);
			
			dp[i][j] %= MOD;
			dp[i][j] += MOD;
			dp[i][j] %= MOD;

		// cout << i << " " << j << " ::: " << dp[i][j] << endl;
		}
	}
	cout << dp[0][n-1] << endl;
}