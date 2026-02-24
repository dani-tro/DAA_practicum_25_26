# include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int d[maxn];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, range;
	cin >> n >> range;
	for(int i = 0; i < n; i++)
	{
		cin >> d[i];
	}

	int l = 0, r = 1;
	long long ans = 0;
	for(l = 0; l < n; l++)
	{
		while(r < n && d[r]-d[l] <= range)
		{
			r ++;
		}
		ans += n - r;
	}

	cout << ans << endl;

}