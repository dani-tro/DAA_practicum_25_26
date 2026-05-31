# include <bits/stdc++.h>
using namespace std;

#define MAX 110000

int n, a[MAX], d[MAX], idx[MAX], par[MAX];

void LIS()
{
	int ans = 0;
	fill(d, d + n + 2, INT_MAX);
	for(int i = 1; i <= n; i++)
	{
		int l = 1, r = n, mid, opt;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if(a[i] <= d[mid])
			{
				r = mid - 1;
				opt = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		d[opt] = a[i];
		idx[opt] = i;
		par[i] = idx[opt - 1];
		ans = max(ans, opt);
	}
	cout << ans << endl;

	int best = idx[ans];
	vector <int> seq;
	while(best != 0) {
		seq.push_back(best);
		best = par[best];
	}

	reverse(seq.begin(),seq.end());
	for (auto x : seq) cout << x << " ";
	cout << endl;

	return ;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	LIS();

	return 0;
}

/*

6
100 2 3 100 8 4


*/