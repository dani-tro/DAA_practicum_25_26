# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
vector <pair <int, int> > g[maxn];
int n, m;
bool vis[maxn];
int k;
void dfs(int v)
{
	vis[v] = true;
	for(auto [u,w] : g[v])
	{
		if (!vis[u] && w >= k) dfs(u);
	}
}
int main()
{
	cin >> n >> m;
	int u, v, w;
	for(int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	cin >> k;

	int counter = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			counter ++;
			dfs(i);
		}
	}

	cout << counter-1 << endl;
}