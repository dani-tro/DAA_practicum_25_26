# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
pair <int, int> a[maxn];
bool cmp(pair <int, int> &i, pair <int, int> &j)
{
	if (i.first < j.first) return true;
	if (j.first < i.first) return false;
	return i.second > j.second;
}
int studio[maxn];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+m, cmp);

	for (int i = 0; i < m; i++)
	{
		int start = a[i].first;
		int dur = a[i].second;
		int best = 0;
		for (int j = 0; j < n; j++)
		{
			// if (studio[j] <= start) {best = j; break;}
			// if (studio[j] < studio[best]) {best = j;}
			if (studio[best] > start && studio[j] < studio[best]) best = j;
		}
		if (studio[best] <= start)
			studio[best] = start + dur;
		else
			studio[best] += dur;
	}

	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (studio[ans] <= studio[i]) ans = i;
	}

	cout << studio[ans] << " " << ans+1 << endl;

}