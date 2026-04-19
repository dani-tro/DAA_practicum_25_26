#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

long long n, m, c, a, b, d, ans[MAX], bestleftx, bestleftcost = LLONG_MAX / 2, bestrightx, bestrightcost = LLONG_MAX / 2;

struct event
{
	long long x, cost, idx;
	
	bool operator<(const event& other) const
	{
		return x < other.x;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> c;
	
	fill(ans, ans + m + 1, LLONG_MAX / 2);
	
	vector<event> v;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({a, b, 0});
	}
	
	for(int i = 1; i <= m; i++)
	{
		cin >> a;
		v.push_back({a, 0, i});
	}
	
	sort(v.begin(), v.end());
	
	for(auto e : v)
	{
		if(e.idx > 0)
		{
			ans[e.idx] = min(ans[e.idx], (e.x - bestleftx) * c + bestleftcost);
		}
		else
		{
			if(bestleftcost + (e.x - bestleftx) * c > e.cost)
			{
				bestleftcost = e.cost;
				bestleftx = e.x;
			}
		}
	}
	
	reverse(v.begin(), v.end());
	
	for(auto e : v)
	{
		if(e.idx > 0)
		{
			ans[e.idx] = min(ans[e.idx], (bestrightx - e.x) * c + bestrightcost);
		}
		else
		{
			if(bestrightcost + (bestrightx - e.x) * c > e.cost)
			{
				bestrightcost = e.cost;
				bestrightx = e.x;
			}
		}
	}
	
	for(int i = 1; i <= m; i++)cout << ans[i] << endl;
	
	return 0;
}
