#include <bits/stdc++.h>

using namespace std;

double L, w[3], g, s[3];

double t(double y1, double y2, int idx)
{
	double res = sqrt(w[idx] * w[idx] + (y1 - y2) * (y1 - y2)) / s[idx];
	return res;
}

double f(double y, int idx)
{
	if(idx == 3)
	{
		return (L - y) / g;
	}
	double l = y, r = L, m1, m2;
	
	for(int i = 0; i < 100; i++)
	{
		m1 = l + (r - l) * (1.0 / 3);
		m2 = l + (r - l) * (2.0 / 3);
		
		double v1 = t(y, m1, idx) + f(m1, idx + 1);
		double v2 = t(y, m2, idx) + f(m2, idx + 1);
		if(v1 > v2)
		{
			l = m1;
		}
		else
		{
			r = m2;
		}
	}
	
	return t(y, m1, idx) + f(m1, idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> L >> g;
	for(int i = 0; i < 3; i++)
	{
		cin >> w[i] >> s[i];
	}
	
	cout << setprecision(10) << f(0 ,0) << endl;
	
	return 0;
}
