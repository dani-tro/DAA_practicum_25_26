#include <bits/stdc++.h>

using namespace std;

#define MAX 1100000

#define MOD 1000000007

long long dp[MAX];

long long rec(int sum)
{	
	if(sum < 0)return 0;
	if(sum == 0)
	{
		return 1;
	}
	
	if(dp[sum] != -1)return dp[sum];
	
	long long ways = 0;
	for(int i = 1; i <= 6; i++)
	{
		ways += rec(sum - i);
		ways %= MOD;
	}
	return dp[sum] = ways;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	fill(dp, dp + n + 5, -1);
	
	cout << rec(n) << endl;
	return 0;
}
