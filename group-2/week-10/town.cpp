#include <bits/stdc++.h>

using namespace std;

#define MAX 210000

int n, a, b, u, v, dist[MAX];

bool used[MAX];

vector<pair<int, int> > gr[MAX];

void BFS01(int node)
{
	deque<pair<int, int> > q;
	
	fill(dist, dist + n + 100, INT_MAX / 100);
	dist[node] = 0;
	q.push_back({dist[node], node});
	
	while(!q.empty())
	{
		node = q.front().second;
		q.pop_front();
		
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
				
				if(dist[u] == dist[node] + 1)
				{
					q.push_back({dist[u], u});
				}
				else if(dist[u] == dist[node])
				{
					q.push_front({dist[u], u});
				}
				
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
	
	cin >> n >> a >> b;
	
	while(cin >> u >> v)
	{
		gr[u].push_back({v, 0});
		gr[v].push_back({u, 1});
	}
	
	BFS01(a);
	
	if(dist[b] == INT_MAX / 100)
	{
		cout << "X" << endl;
	}
	else
	{
		cout << dist[b] << endl;
	}
	
	return 0;
}
