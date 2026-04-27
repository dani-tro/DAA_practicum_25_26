# include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
string names[maxn];
map <string, int> mp;
set <int> g[maxn];
bool popular[maxn];
int cnt[maxn];
int curr = 0;
int getid(string& s)
{
	if (mp.find(s) != mp.end())// mp.count(s) > 0
	{
		return mp[s];
	}
	names[curr] = s;
	mp[s] = curr;
	curr++;
	return curr - 1;
}
int main()
{
	int n, k, f, m;
	cin >> n >> k >> f >> m;
	string s;
	for (int i = 1; i <= f; i++)
	{
		cin >> s;
		names[curr] = s; 
		popular[curr] = true;
		mp[s] = curr;
		curr++;
	}
	string p;
	for (int i = 1; i <= m; i++)
	{
		cin >> s >> p;
		int u = getid(s);
		int v = getid(p);
		g[u].insert(v);
		g[v].insert(u);
	}
	queue <int> famous;
	for (int i = 0; i < n; i++)
	{
		if (popular[i]) {
			cnt[i] = 0;
			famous.push(i);
		}
		else cnt[i] = k;
	}
	// cout << "OK" << endl;
	while(!famous.empty())
	{
		auto u = famous.front();
		famous.pop();
		for (auto v : g[u])
		{
			if (!popular[v])
			{
				cnt[v] --;
				if (cnt[v] == 0)
				{
					popular[v] = true;
					famous.push(v);
				}
			}
		}
	}
	vector <string> T;
	for (int i = 0; i < n; i++)
	{
		if (popular[i]) // names[i]
		{
			T.push_back(names[i]);
		}
	}
	sort(T.begin(), T.end());
	for(auto s: T)
		cout << s << " ";
	cout << endl;
}