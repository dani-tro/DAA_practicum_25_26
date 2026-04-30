# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
vector <int> g[maxn];
int n, m;
bool vis[maxn];
int comp[maxn];
int curr;
void dfs(int v)
{
	vis[v] = true;
	comp[v] = curr;
	for(auto u : g[v])
	{
		if (!vis[u]) dfs(u);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
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
			curr++;
			dfs(i);
		}
	}

	int q;
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		cin >> u >> v;
		cout << (comp[u]==comp[v]);
	}
	cout << '\n';
}