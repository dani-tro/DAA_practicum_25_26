#include <bits/stdc++.h>

using namespace std;

#define MAX 11000

#define PA pair<int, int> 

int n, mat[MAX][MAX], t, dist[MAX * 4];

vector<PA> gr[MAX * 4];

bool used[4 * MAX];

int code(int i, int j)
{
	return ((i - 1) * n + j - 1);
}

void add_edge(int i1, int j1, int i2, int j2)
{
	int a = code(i1, j1);
	int b = code(i2, j2);
	gr[a].push_back({b, 3 * t + mat[i2][j2]});
	
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

int main()
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
	
	for(int i1 = 1; i1 <= n; i1++)
	{
		for(int j1 = 1; j1 <= n; j1++)
		{
			for(int i2 = 1; i2 <= n; i2++)
			{
				for(int j2 = 1; j2 <= n; j2++)
				{	
					if(abs(i1 - i2) + abs(j1 - j2) == 1 || abs(i1 - i2) + abs(j1 - j2) == 3)
					{
						add_edge(i1, j1, i2, j2);
					}
				}
			}
		}
	}
	
	dijkstra(code(1, 1));
	
	cout << min({dist[code(n, n)], dist[code(n - 1, n)] + t, dist[code(n, n - 1)] + t,
	dist[code(n - 1, n - 1)] + 2 * t, dist[code(n - 2, n)] + 2 * t, dist[code(n, n - 2)] + 2 * t}) << endl;
	
	return 0; 
}
