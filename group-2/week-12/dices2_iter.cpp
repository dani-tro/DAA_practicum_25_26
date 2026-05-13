#include <bits/stdc++.h>

using namespace std;

#define MAXS 6100

#define MAXK 1100

#define MOD 1000000007

long long dp[MAXS][MAXK];

long long calc(int s, int k)
{	
	dp[0][0] = 1;
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= s; j++)
		{
			for(int l = 1; l <= min(6, j); l++)
			{
				dp[j][i] += dp[j - l][i - 1];
				dp[j][i] %= MOD;
			}
		}
	}
	return dp[s][k];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int s, k;
	cin >> k >> s;
	
	cout << calc(s, k) << endl;
	
	return 0;
}
