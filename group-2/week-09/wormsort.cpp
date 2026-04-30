# include <bits/stdc++.h>
using namespace std;
# define int long long
const int maxn = 1e5+5;
int p[maxn];
vector <pair<int,int> > g[maxn];
int weights[maxn];
int comp[maxn];
bool vis[maxn];
int n, m;
void dfs(int v, int minw, int compid)
{
	vis[v] = true;
	comp[v] = compid;
	for (auto [u,w] : g[v])
	{
		if (!vis[u] && w >= minw)dfs(u,minw, compid);
	}
}
bool check(int mid)
{
	for (int i = 1; i <= n; i++)
	{
		vis[i] = false;
		comp[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])dfs(i, mid, i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (comp[i] != comp[p[i]]) return false;
	}
	return true;
}
signed main()
{
	cin >> n >> m;
	int u,v,w;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		weights[i] = w;
	}
	weights[m+1] = 1e9+1;
	sort(weights+1,weights+m+1);

	int l = 1, r = m+1, mid;
	while(l < r)
	{
		// cout << l << " " << r << endl;
		mid = (l+r+1)/2;
		if (check(weights[mid])) l = mid;
		else	r = mid - 1;
	}
	cout << (l == m+1 ? -1 : weights[l]) << endl;

}