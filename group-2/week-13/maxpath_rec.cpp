# include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
vector < pair <int, int> > g[maxn];
int dp[maxn];
int s,t;
int dfs(int v)
{
	if (v == t) return dp[v]=0;
	if (dp[v] != INT_MIN) return dp[v];
	for (auto [u,w] : g[v])
	{
		dp[v] = max(dp[v], dfs(u)+w);
	}
	return dp[v];
}

int main()
{
	int n, m;
	cin >> n >> m;
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{	
		cin >> u >> v >> w;
		g[u].push_back({v,w});
	}
	cin >> s >> t;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = INT_MIN;
	}
	// dp[t] = 0;
	dfs(s);
	cout << dp[s] << endl;
}