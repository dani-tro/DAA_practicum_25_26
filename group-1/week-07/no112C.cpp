#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

int n, m, q, a, b, comp[MAX], c;

vector<int> gr[MAX];

bool used[MAX];

void dfs(int u)
{
	comp[u] = c;
	used[u] = true;
	
	for(auto v : gr[u])
	{
		if(!used[v])
		{	
			dfs(v);
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
	
	for(int i = 1; i <= n; i++)
	{
		if(!used[i])
		{
			c++;
			dfs(i);
		}
	}
	
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> a >> b;
		cout << (comp[a] == comp[b]);
	}
	cout << endl;
	
	return 0;
}
