#include <bits/stdc++.h>

using namespace std;

#define MAX 128

int n, m, a, b;

vector<int> gr[MAX];

bool used[MAX];

void dfs(int u)
{
	used[u] = true;
	cout << u << " ";
	
	for(auto v : gr[u])
	{
		if(!used[v])
		{	
			dfs(v);
		}
	}
	
	return ;
}

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	used[u] = true;

	while(!q.empty())
	{
		u = q.front();
		cout << u << " ";
		q.pop();
			
		for(auto v : gr[u])
		{
			if(!used[v])
			{
				q.push(v);
				used[v] = true;
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
	
	for(int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	
	for(int i = 0; i < n; i++)
	{
		sort(gr[i].begin(), gr[i].end());
	}
	
	bfs(0);
	cout << endl;
	
	return 0;
}
