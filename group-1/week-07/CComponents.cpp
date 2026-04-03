#include <bits/stdc++.h>

using namespace std;

#define MAX 1100000

int n, m, a, b, ans;

bool used[MAX];

vector<int> gr[MAX];

void dfs(int u)
{
	used[u] = true;
	for(auto v : gr[u])
	{
		if(!used[v])
		{
			dfs(v);
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
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!used[i])
		{
			dfs(i);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
