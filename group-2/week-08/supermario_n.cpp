#include <bits/stdc++.h>

using namespace std;

#define MAX 11000000

long long n, k, f, a, b, m, arr[MAX], d[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	cin >> f >> a >> b >> m;
	
	arr[1] = f;
	for(int i = 2; i <= n; i++)
	{
		arr[i] = (arr[i - 1] * a + b) % m;
	}
	
	deque<pair<long long, int> > q;
	
	q.push_front({0, 0});
	
	for(int i = 1; i <= n + 1; i++)
	{
		while(!q.empty() && q.front().second < i - k)
		{
			q.pop_front();
		}
		d[i] = q.front().first + arr[i];
		
		while(!q.empty() && q.back().first > d[i])
		{
			q.pop_back();
		}
		
		q.push_back({d[i], i});
	}
	
	cout << d[n + 1] << endl;
	
	return 0;
}
