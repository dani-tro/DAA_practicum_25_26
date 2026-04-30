# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
vector <int> g[maxn];
int n, m;
bool vis[maxn];
void dfs(int v)
{
	vis[v] = true;
	for(auto u : g[v])
	{
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

	int counter = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			counter ++;
			dfs(i);
		}
	}

	cout << counter << endl;
}