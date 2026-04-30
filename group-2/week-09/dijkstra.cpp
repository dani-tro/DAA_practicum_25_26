#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

#define INF 1e14

#define PA pair<int, int>

long long n, m, dist[MAX], a, b, c, s;

bool used[MAX];

vector<pair<int, int> > gr[MAX];

void dijkstra(int node)
{
	priority_queue<PA, vector<PA>, greater<PA> > pq; // increasing
	fill(dist, dist + n + 10, LLONG_MAX / 10);
	
	dist[node] = 0;
	pq.push({dist[node], node});
	
	while(!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		
		if(used[node])continue;
		used[node] = true;
		
		for(auto e : gr[node])
		{
			int u = e.first;
			if(dist[u] > dist[node] + e.second)
			{
				dist[u] = dist[node] + e.second;
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
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		gr[a].push_back({b, c});
		gr[b].push_back({a, c});
	}
	
	cin >> s;
	
	dijkstra(s);
	
	for(int i = 0; i < n; i++)cout << dist[i] << " ";
	cout << endl;
	
	return 0;
}
