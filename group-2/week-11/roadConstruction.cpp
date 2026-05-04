#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

int n, m, a, b, ccomp, par[MAX], sz[MAX], mxcomp = 1, d[MAX];

int find(int a)
{
	if(par[a] == 0)return a;
	return par[a] = find(par[a]);
}

void myUnion(int a, int b)
{
	a = find(a);
	b = find(b);
	
	if(a == b)
	{
		return;
	}
	
	ccomp--;
	
	if(d[a] > d[b])
	{
		par[b] = a;
		sz[a] += sz[b];
		mxcomp = max(mxcomp, sz[a]);
	}
	else
	{
		par[a] = b;
		sz[b] += sz[a];
		mxcomp = max(mxcomp, sz[b]);
		if(d[a] == d[b])
		{
			d[b]++;	
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	fill(sz + 1, sz + n + 1, 1); // for(int i = 1; i <= n; i++) sz[i] = 1;
	ccomp = n;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		myUnion(a, b);
		cout << ccomp << " " << mxcomp << endl;
	}
	
	return 0;
}
