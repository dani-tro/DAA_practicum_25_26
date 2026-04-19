#include <bits/stdc++.h>

using namespace std;

#define MAX 128

int n, m, a, b;

bool mat[MAX][MAX], used[MAX];

void dfs(int u)
{
	used[u] = 1;
	cout << u << " ";
	for(int v = 0; v <= n - 1; v++)
	{
		if(mat[u][v] == 1)
		{
			if(!used[v])
			{
				dfs(v);
			}
		}
	}
	
	return;
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
			
		for(int v = 0; v <= n - 1; v++)
		{
			if(mat[u][v])
			{
				if(!used[v])
				{
					q.push(v);
					used[v] = true;
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
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		mat[a][b] = 1;
		mat[b][a] = 1; // undirected
	}
	
	//dfs(0);
	bfs(0);
	cout << endl;
	
	return 0;
}
