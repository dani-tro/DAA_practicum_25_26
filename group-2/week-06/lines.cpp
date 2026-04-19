#include <bits/stdc++.h>

using namespace std;

#define MAX 610000

int n, x_1, y_1, x_2, y_2, ans, sum;

struct event
{
	int coord;
	int fl;
	
	bool operator<(const event& other) const
	{
		if(coord == other.coord)
			return fl > other.fl;
		return coord < other.coord;
	}
} arrx[MAX], arry[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	
	cin >> n;
	
	for(int i = 0; i < 2 * n; i += 2)
	{
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		if(x_1 > x_2)swap(x_1, x_2);
		if(y_1 > y_2)swap(y_1, y_2);
		
		arrx[i] = {x_1, 1};
		arrx[i + 1] = {x_2, -1};
		
		arry[i] = {y_1, 1};
		arry[i + 1] = {y_2, -1};
	}
	
	sort(arrx, arrx + 2 * n);
	sort(arry, arry + 2 * n);
	
	for(auto e : arrx)
	{
		sum += e.fl;
		ans = max(ans, sum);
	}
	
	for(auto e : arry)
	{
		sum += e.fl;
		ans = max(ans, sum);
	}
	
	cout << ans << endl;
	return 0;
}
