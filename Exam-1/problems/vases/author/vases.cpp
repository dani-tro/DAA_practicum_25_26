#include <bits/stdc++.h>

using namespace std;

#define MAX 11000000

long long n, h, a[MAX];

bool check(long long len)
{
	long long res = 0;
	for(int i = n; i >= 1; i -= len)
	{
		res += a[i];
	}
	return res <= h;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> h;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	long long l = 1, r = MAX, mid, opt;
	
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(check(mid))
		{
			r = mid - 1;
			opt = mid;
		}
		else l = mid + 1;
	}
	
	cout << opt << endl;
	return 0;
}
