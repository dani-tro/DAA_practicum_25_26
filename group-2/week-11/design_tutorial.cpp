#include <bits/stdc++.h>

using namespace std;

#define MAX 2005
int par[MAX], d[MAX], cnt;
int n, a[MAX][MAX];

struct edge
{
	int a, b, c;
	bool operator<(const edge& other)
	{
		return c < other.c;
	}
};

vector<edge> edges;

int find(int a)
{
	if(par[a] == -1)return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	cnt++;
	a = find(a);
	b = find(b);
	if(d[a] > d[b])
	{
		par[b] = a;
	}
	else
	{
		par[a] = b;
		if(d[a] == d[b])d[b]++;
	}
	return;
}
vector <pair <int, int> > g[MAX];
long long dist[MAX];
void dfs(int v, long long d, int par = -1) {
	dist[v] = d;
	for (auto [u,w] : g[v])
	{
		if (u == par)continue;
		dfs(u, d+w, v);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	fill(par,par+n,-1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (i < j)
				edges.push_back({i,j,a[i][j]});
			if (i != j && a[i][j] == 0){
				cout << "NO" << endl;
				return 0;
			}
		}
	
	sort(edges.begin(), edges.end());
	// cout << "OK" << endl;
	
	for (auto e : edges){
		if (find(e.a) != find(e.b)) {
			uni(e.a, e.b);
			g[e.a].push_back({e.b,e.c});
			g[e.b].push_back({e.a,e.c});
		}
	}
	for (int i = 0; i < n; i++)
	{
		dfs(i, 0);
		for (int j = 0; j < n; j++)
		{
			if (dist[j] != a[i][j])
			{
				cout << "NO" << endl;
				return 0;
			}
		}

	}
	cout << "YES" << endl;
 	
	return 0;
}
