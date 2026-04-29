# include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
vector <int> g[maxn];
int n, m;
bool vis[maxn];
void bfs(int start)
{
	queue <int> q;
	q.push(start);
	vis[start] = true;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (auto u : g[v])
		{
			if (!vis[u])
			{
				vis[u] = true;
				q.push(u);
			}
		}
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
	bfs(0);
	cout << endl;
}