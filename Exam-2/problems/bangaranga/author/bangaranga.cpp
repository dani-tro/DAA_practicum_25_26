#include <bits/stdc++.h>

using namespace std;

#define MAX 251000

#define int long long

#define MAXN 512

#define PA pair<int, long long> 

long long n, mat[MAXN][MAXN], t, dist[MAX * 4];

vector<PA> gr[MAX * 4];

bool used[4 * MAX];

int code(int i, int j, int k)
{
	return ((i - 1) * n + j - 1) + n * n * k;
}

void add_edges(int i1, int j1, int i2, int j2)
{
	if(i2 < 1 || i2 > n)return ;
	if(j2 < 1 || j2 > n)return ;
	
	for(int k = 0; k <= 2; k++)
	{
		int a = code(i1, j1, k);
		int b = code(i2, j2, (k + 1) % 3);
		if(k != 2)
		{
			gr[a].push_back({b, t});
		}
		else
		{
			gr[a].push_back({b, t + mat[i2][j2]});
		}
	}
	
	return;
}

void dijkstra(int node)
{
	fill(dist, dist + 4 * MAX, INT_MAX);
	dist[node] = 0;
	
	priority_queue<PA, vector<PA>, greater<PA> > pq;

	pq.push({dist[node], node});
	
	while(!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		if(used[node])continue;
		used[node] = 1;
		
		for(auto e : gr[node])
		{
			int u = e.first;
			int w = e.second;
			if(dist[u] > dist[node] + w)
			{
				dist[u] = dist[node] + w;
				pq.push({dist[u], u});
			}
		}
	}
	return ;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> t;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> mat[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			add_edges(i, j, i + 1, j);
			add_edges(i, j, i - 1, j);
			add_edges(i, j, i, j + 1);
			add_edges(i, j, i, j - 1);
		}
	}
	
	dijkstra(code(1, 1, 0));
	
	cout << min({dist[code(n, n, 0)], dist[code(n, n, 1)], dist[code(n, n, 2)]}) << endl;
	
	return 0; 
}
