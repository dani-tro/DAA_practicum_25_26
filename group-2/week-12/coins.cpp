#include <bits/stdc++.h>

using namespace std;

#define MAX 1010000

#define INF 1e7

int n, x, c[MAX], dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	
	cin >> n >> x;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	
	fill(dp, dp + x + 10, INF);
	
	dp[0] = 0;
	
	for(int i = 1; i <= x; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i >= c[j])
			{
				dp[i] = min(dp[i - c[j]] + 1, dp[i]);
			}
		}	
	}
	if(dp[x] != INF)
	{
		cout << dp[x] << endl;
	}
	else 
	{
		cout << "-1" << endl;
	}
	
	return 0;
}
