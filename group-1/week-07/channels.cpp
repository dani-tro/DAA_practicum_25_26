#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

int n, m, a, b, c, k, ans;

bool used[MAX];

vector<pair<int, int> > gr[MAX];

void dfs(int u)
{
	used[u] = true;
	for(auto v : gr[u])
	{
		if(!used[v.first] && v.second >= k)
		{
			dfs(v.first);
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
	
	for(int i = 1; i <= n; i++)
	{
		if(!used[i])
		{
			dfs(i);
			ans++;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
