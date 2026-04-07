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
	
	arr[0] = 0;
	
	priority_queue<pair<long long, int> > pq;
	pq.push({0, 0});
	
	for(int i = 1; i <= n + 1; i++)
	{
		while(!pq.empty() && pq.top().second < i - k)
		{
			pq.pop();
		}
		
		d[i] = arr[i] + (-pq.top().first);
		pq.push({-d[i], i});
	}
	
	cout << d[n + 1] << endl;
	
	return 0;
}
