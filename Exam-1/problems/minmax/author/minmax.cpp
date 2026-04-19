#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

long long n, s, a[MAX], ans, cntmin = 0, cntmax = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> s;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	int l = 1, r = n;
	while(l < n && a[l] == a[l + 1])l++;
	while(r > 1 && a[r] == a[r - 1])r--;
	if(a[l] == a[r])
	{
		cout << 0 << endl;
		return 0;
	}
	
	cntmin = l;
	cntmax = n - r + 1;
	
	while(a[l] < a[r])
	{
		if(cntmin < cntmax)
		{
			int delta = (a[l + 1] - a[l]);
			if(delta * cntmin > s)
			{
				a[l] += s / cntmin;
				cout << (a[r] - a[l]) << endl;
				return 0;
			}
			l++;
			s -= delta * cntmin;
			cntmin++;
			while(l < n && a[l] == a[l + 1])
			{
				l++;
				cntmin++;
			}
		}
		else
		{
			int delta = (a[r] - a[r - 1]);
			if(delta * cntmax > s)
			{
				a[r] -= s / cntmax;
				cout << (a[r] - a[l]) << endl;
				return 0;
			}
			r--;
			s -= delta * cntmax;
			cntmax++;
			while(r > 1 && a[r] == a[r - 1])
			{
				r--;
				cntmax++;
			}
		}
	}
	cout << (a[r] - a[l]) << endl;
	
	return 0;
}
