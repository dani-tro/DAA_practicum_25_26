#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

#define PA pair<long long, long long> 

vector<PA> gr[MAX];

long long n, m, a, b, c, k, q, dist[MAX];

bool used[MAX];

void dijkstra(int node)
{
	priority_queue<PA> pq;
	fill(dist, dist + n + 100, LLONG_MAX / 10);
	
	dist[node] = 0;
	pq.push({-dist[node], node});
	
	while(!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		
		if(used[node])
		{
			continue;
		}
		used[node] = true;
		
		for(auto e : gr[node])
		{
			int u = e.first;
			if(dist[u] > dist[node] + e.second)
			{
				dist[u] = dist[node] + e.second;
				pq.push({-dist[u], u});
			}
		}
	}
	return;
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
	
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> a;
		gr[n].push_back({a, 0});
		gr[a].push_back({n, 0});
	}
	
	
	dijkstra(n);
	
	cin >> q;
	
	for(int i = 0; i < q; i++)
	{
		cin >> a;
		cout << dist[a] << endl;
	}
	
	return 0;
}
