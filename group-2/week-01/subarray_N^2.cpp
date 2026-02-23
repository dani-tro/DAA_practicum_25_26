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
		long long arr = 0;
		for(int r = l; r < n; r++)
		{
			arr += a[r];
			if ((r-l+1)%2==1)
				sum += arr;
		}
	}

	cout << sum << endl;
}