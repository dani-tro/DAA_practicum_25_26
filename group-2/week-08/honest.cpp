# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
vector <pair <int, int> > g[maxn];
int n, m;
bool vis[maxn];
int k;
int cnt[2];
void dfs(int v, bool is_liar)
{
	vis[v] = true;
	cnt[is_liar]++;
	for(auto [u,w] : g[v])
	{
		if (!vis[u]) dfs(u, (w != is_liar));
		// if (!vis[u]) dfs(u, w ^ is_liar);
	}
}
int main()
{
	cin >> n >> m;
	int u, v;
	char w;
	for(int i = 1; i <= m; i++)
	{
		cin >> u >> w >> v;
		g[u].push_back({v,(w=='l')});
		g[v].push_back({u,(w=='l')});
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			cnt[0] = cnt[1] = 0;
			dfs(i, 0);
			ans += max(cnt[0],cnt[1]);
		}
	}

	cout << ans << endl;
}
/*
5 9
1 h 2
2 h 3
1 l 4
2 l 4
5 h 4
3 l 4
1 l 5
2 l 5
5 l 3
*/