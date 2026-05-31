# include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
vector < pair <int, int> > g[maxn];
int dp[maxn];
int in[maxn];
int main()
{
	int n, m;
	cin >> n >> m;
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{	
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		in[v] ++;
	}
	int s,t;
	cin >> s >> t;
	queue <int> q;
	vector <int> topo;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)q.push(i);
		dp[i] = INT_MIN;
	}
	dp[s] = 0;
	while(!q.empty())
	{
		int v = q.front();
		topo.push_back(v);
		q.pop();
		for (auto [u,w] : g[v])
		{
			in[u] --;
			if (in[u] == 0) q.push(u);
		}
	}
	for (auto v : topo)
	{
		cout << v << " ";
		for (auto [u,w] : g[v]) {
			dp[u] = max(dp[u], dp[v] + w);
		}
	}
	cout << endl;
	cout << dp[t] << endl;
}