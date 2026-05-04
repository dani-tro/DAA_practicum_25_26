#include <bits/stdc++.h>

using namespace std;

#define MAX 210000

int n, m, a, b, par[MAX], sz[MAX], d[MAX], q, t, pos, tc;

string s, cp;

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
	
	if(d[a] > d[b])
	{
		par[b] = a;
		sz[a] += sz[b];
	}
	else
	{
		par[a] = b;
		sz[b] += sz[a];
		if(d[a] == d[b])
		{
			d[b]++;	
		}
	}
	
}

void solve()
{
	cin >> s;
	cin >> q;
	
	n = s.size();
	fill(sz, sz + n, 1);
	fill(par, par + n, 0);
	fill(d, d + n, 0);
	
	cp = s;
	
	vector<pair<int, int> > v;
	for(int i = 0; i < q; i++)
	{
		cin >> t >> pos;
		v.push_back({t, pos});
		if(t == 2)
		{
			s[pos] = '#';
		}
		
	}
	
	for(int i = 1; i < n; i++)
	{
		if(s[i] == s[i - 1] && s[i] != '#')
		{
			myUnion(i - 1, i);
		}
	}
	
	stack<int> ans;
	for(int i = v.size() - 1; i >= 0; i--)
	{
		if(v[i].first == 1)
		{
			ans.push(sz[find(v[i].second)]);
		}
		else
		{
			pos = v[i].second;
			s[pos] = cp[pos];
			if(pos > 0 && s[pos - 1] == s[pos])
			{
				myUnion(pos - 1, pos);
			}
			if(pos < n - 1 && s[pos] == s[pos + 1])
			{
				myUnion(pos, pos + 1);
			}
		}
	}
	
	while(!ans.empty())
	{
		cout << ans.top() << "\n";
		ans.pop();
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> tc;
	
	for(int i = 1; i <= tc; i++)
	{
		cout << "Case " << i << ":\n";
		solve();
	}
	
	
	return 0;
}
