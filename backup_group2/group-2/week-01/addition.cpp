# include <bits/stdc++.h>
using namespace std;

long long sum;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		long long a;
		cin >> a;
		sum += a;
	}

	cout << sum << endl;
}