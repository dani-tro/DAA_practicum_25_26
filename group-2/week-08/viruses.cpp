# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
vector <int> g[maxn];
int n, m, k, counter, x, y;
bool vis[maxn];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {-1, 0, 0, 1};

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

			for(int t = 0; t < 4; t++)
			{
				if(valid(i + dx[t], j + dy[t]))
				{
					v = code(i + dx[t], j + dy[t]);
					g[u].push_back(v);
					g[v].push_back(u);
				}
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