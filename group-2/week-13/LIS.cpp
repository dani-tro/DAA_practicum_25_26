# include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int a[maxn];
int dp[maxn];
int par[maxn];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dp[1] = 1;
	for (int j = 2; j <= n; j++)
	{
		dp[j] = 1;
		for(int i = 1; i < j; i++)
		{
			if (a[i] < a[j])
			{
				if (dp[j] < dp[i] + 1) {
					dp[j] = dp[i] + 1;
					par[j] = i;
				}
			}
		}
	}
	int ans = 0, best;
	for (int i = 1; i <= n; i++) {
		if (ans < dp[i]) {
			ans = dp[i];
			best = i;
		}
	}
	vector <int> seq;
	while(best != 0) {
		seq.push_back(best);
		best = par[best];
	}

	cout << ans << endl;
	reverse(seq.begin(),seq.end());
	for (auto x : seq) cout << x << " ";
	cout << endl;

}

/*
6
100 2 3 100 8 4


*/