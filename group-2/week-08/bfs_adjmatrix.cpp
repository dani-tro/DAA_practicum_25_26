# include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int A[maxn][maxn];
bool vis[maxn];
int n, m;
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
		for (int i = 0; i < n; i++)
		{
			if (A[v][i] && !vis[i])
			{
				vis[i] = true;
				q.push(i);
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
		A[u][v] = 1;
		A[v][u] = 1;
	}

	bfs(0);
	cout << endl;
}