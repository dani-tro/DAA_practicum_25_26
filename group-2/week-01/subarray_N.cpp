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
	for(int i = 0; i < n; i++)
	{
		long long peven = i/2+1;
		long long neven = (n-1-i)/2 + 1;
		long long podd = (i+1)/2;
		long long nodd = (n-i)/2;
		long long cnt = peven*neven+podd*nodd;
		sum += cnt*a[i];
	}

	cout << sum << endl;
}