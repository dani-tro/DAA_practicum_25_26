# include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
vector <int> g[maxn];
int n, m;
bool vis[maxn];
void dfs(int v)
{
	vis[v] = true;
	cout << v << " ";
	// sort(g[v].begin(), g[v].end());
	// for (int i = 0; i < g[v].size(); i++)
	for(auto u : g[v])
	{
		// int u = g[v][i];
		if (!vis[u]) dfs(u);
	}
}
int main()
{
	cin >> n >> m;
	int u, v;
	for(int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		sort(g[i].begin(), g[i].end());
	dfs(0);
	cout << endl;
}