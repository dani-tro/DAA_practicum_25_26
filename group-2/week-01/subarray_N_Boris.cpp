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
		int cnt = ((i+1)*(n-i)+1)/2;
		sum += a[i]*cnt;
	}

	cout << sum << endl;
}