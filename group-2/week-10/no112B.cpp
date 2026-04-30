#include <bits/stdc++.h>

using namespace std;

#define MAX 210000

int n, m, a, b, q, t, par[MAX], d[MAX];

int find(int u)
{
	if(par[u] == -1)return u;
	return par[u] = find(par[u]);
}

void myUnion(int u, int v)
{
	u = find(u);
	v = find(v);
	if(u == v)return;
	
	if(d[u] > d[v])
	{
		par[v] = u;
	}
	else
	{
		par[u] = v;
		if(d[v] == d[u])
		{
			d[v]++;
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
	
	fill(par, par + n + 1, -1);
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		myUnion(a, b);
	}
	
	cin >> q;
	
	for(int i = 0; i < q; i++)
	{
		cin >> t >> a >> b;
		if(t == 1)
		{
			cout << (find(a) == find(b));
		}
		else if(t == 2)
		{
			myUnion(a, b);
		}
	}
	
	cout << endl;
	return 0;
}
