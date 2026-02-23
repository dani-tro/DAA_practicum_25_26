# include <bits/stdc++.h>
using namespace std;
long long a[10005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	long long sum = 0;
	for(int l = 0; l < n; l++)
	{
		for(int r = l; r < n; r+=2)
		{
			long long arr = 0;
			for(int t = l; t <= r; t++)
				arr += a[t];
			sum += arr;
		}
	}

	cout << sum << endl;
}