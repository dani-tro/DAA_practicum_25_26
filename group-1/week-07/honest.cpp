#include <bits/stdc++.h>

using namespace std;

#define MAX 10100

int n, m, a, b, ans;

char c;

vector<pair<int, char> > gr[MAX];

bool used[MAX];

pair<int, int> dfs(int u, bool flag)
{
	used[u] = true;
	
	int cnt_all = 1, cnt_honest = (flag);
	for(auto e : gr[u])
	{
		int v = e.first;
		if(!used[v])
		{
			if(e.second == 'l')
			{
				auto p = dfs(v, !flag);
				cnt_all += p.first;
				cnt_honest += p.second;
			}
			else
			{
				auto p = dfs(v, flag);
				cnt_all += p.first;
				cnt_honest += p.second;
			}
		}
	}
	return {cnt_all, cnt_honest};
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++)
	{
		cin >> a >> c >> b;
		gr[a].push_back({b, c});
		gr[b].push_back({a, c});
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!used[i])
		{
			auto p = dfs(i, 1);
			ans += max(p.second, p.first - p.second);
		}
	}

	cout << ans << endl;
	return 0;
}

/*

10 9
6 h 2
10 h 7
3 l 5
6 l 7
6 l 8
4 l 1
2 l 7
1 h 7
8 h 9 

*/
