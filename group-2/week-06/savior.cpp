#include <bits/stdc++.h>

using namespace std;

int t;

double xa, ya, xb, yb, v1, v2;

double f(double x)
{
	double res = sqrt((xa - x) * (xa - x) + ya * ya) / v1 + 
				 sqrt((xb - x) * (xb - x) + yb * yb) / v2;
	return res;
}

void solve()
{
	cin >> xa >> ya >> xb >> yb >> v1 >> v2;
	
	double l = min(xa, xb), r = max(xa, xb), m1, m2;
	
	for(int i = 0; i < 200; i++)
	{
		m1 = l + (r - l) * (1.0 / 3);
		m2 = l + (r - l) * (2.0 / 3);
		
		double f1 = f(m1), f2 = f(m2);
		
		if(f1 > f2)
		{
			l = m1;
		}
		else
		{
			r = m2;
		}	
	}
	
	cout << fixed << setprecision(5) << f(l) << endl;
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		solve();
	}
	
	return 0;
}
