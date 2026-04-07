#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

int n, a[MAX], ans[MAX];

stack<pair<int, int> > s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	s.push({INT_MIN, 0});
	
	for(int i = 1; i <= n; i++)
	{
		while(!s.empty() && s.top().first >= a[i])
		{
			s.pop();
		}
		ans[i] = s.top().second;
		s.push({a[i], i});
	}
	
	for(int i = 1; i <= n; i++)cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}
