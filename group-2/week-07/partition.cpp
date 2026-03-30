#include <bits/stdc++.h>

using namespace std;

struct point
{
	double x, y;
} a, b, c, p;

double L, ar;

double area(point &a, point &b, point &c)
{
	double res = abs((b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y)) / 2;
	return res;
}

void bin_search(point u, point v)
{
	double l = 0.0, r = 1.0, mid;
	
	for(int i = 0; i < 128; i++)
	{
		mid = (l + r) * (1.0 / 2);
		point q = {mid * u.x + (1.0 - mid) * v.x, mid * u.y + (1.0 - mid) * v.y};
		
		double pqu = area(p, q, u);
		
		if(pqu > (ar - pqu))
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	
	cout << std::fixed << std::setprecision(6) << mid * u.x + (1.0 - mid) * v.x << " " << mid * u.y + (1.0 - mid) * v.y << endl;
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> L >> b.x >> b.y;
	
	a = {0, 0};
	c = {0, L};
	
	ar = area(a, b, c);
	
	cin >> p.x >> p.y;
	
	if(area(p, c, a) == 0.0)
	{
		if(area(a, b, p) > area(b, c, p))
		{
			bin_search(a, b);
		}
		else
		{
			bin_search(c, b);
		}
	}
	else if(area(p, c, b) == 0.0)
	{
		if(area(a, b, p) > area(a, c, p))
		{
			bin_search(b, a);
		}
		else
		{
			bin_search(c, a);
		}
	}
	else if(area(p, b, a) == 0.0)
	{
		if(area(a, c, p) > area(b, c, p))
		{
			bin_search(a, c);
		}
		else
		{
			bin_search(b, c);
		}
	}
	
	
	return 0;
}
