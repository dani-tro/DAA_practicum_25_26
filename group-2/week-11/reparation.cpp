# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct edge {
	int u, v, w;
};
bool cmp(edge i, edge j)
{
	return i.w < j.w;
}
vector <edge> g;
int par[maxn], d[maxn];
int find(int v)
{
	if (par[v] == 0) return v;
	return par[v] = find(par[v]);
}
void myunion(int u, int v)
{
	u = find(u);
	v = find(v);
	if (d[u] > d[v]) swap(u,v);
	par[u] = v;
	if (d[u] == d[v])d[v]++;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	int u, v, w;
	for(int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		g.push_back({u,v,w});
	}
	sort(g.begin(), g.end(), cmp);
	long long sum = 0;
	int comp = n;
	for (auto e : g) {
		u = find(e.u);
		v = find(e.v);
		if (u != v) {
			sum += e.w;
			myunion(u, v);
			comp --;
		}
	}
	if (comp > 1) {
		cout << "IMPOSSIBLE" << endl;
	} else
		cout << sum << endl;
}