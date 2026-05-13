#include <bits/stdc++.h>

using namespace std;

#define MAXS 6100

#define MAXK 1100

#define MOD 1000000007

long long dp[MAXS][MAXK];

long long rec(int s, int k)
{	
	//if(1 <= s && s <= 6 && k == 1)return dp[s][k] = 1;
	if(s == 0 && k == 0)return dp[s][k] = 1;
	
	if(dp[s][k] != -1)return dp[s][k];
	
	dp[s][k] = 0;
	for(int i = 1; i <= min(6, s); i++)
	{
		dp[s][k] += rec(s - i, k - 1);
		dp[s][k] %= MOD;
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
	
	for(int i = 0; i <= s; i++)
	{
		for(int j = 0; j <= k; j++)dp[i][j] = -1;
	}
	
	cout << rec(s, k) << endl;
	return 0;
}
