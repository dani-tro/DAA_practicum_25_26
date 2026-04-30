# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
vector <int> g[maxn];
int n, m, k, counter, x, y;
bool vis[maxn];
void dfs(int v)
{
	vis[v] = true;
	for(auto u : g[v])
	{
		if (!vis[u]) dfs(u);
	}
}

int code(int i, int j)
{
	return (i - 1) * m + j;
}

bool valid(int x, int y)
{
	return (1 <= x && x <= n && 1 <= y && y <= m);
}

int main()
{
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int u = code(i, j);
			
			int v;
			if(valid(i + 1, j))
			{
				v = code(i + 1, j);
				g[u].push_back(v);
				g[v].push_back(u);
			}

			if(valid(i - 1, j))
			{
				v = code(i - 1, j);
				g[u].push_back(v);
				g[v].push_back(u);
			}

			if(valid(i, j + 1))
			{
				v = code(i, j + 1);
				g[u].push_back(v);
				g[v].push_back(u);
			}

			if(valid(i, j - 1))
			{
				v = code(i, j - 1);
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
	}
	
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> x >> y;
		int u = code(x, y);
		vis[u] = 1;
	}


	for (int i = 1; i <= n * m; i++)
	{
		if (!vis[i])
		{
			counter ++;
			dfs(i);
		}
	}

	cout << counter << endl;
}