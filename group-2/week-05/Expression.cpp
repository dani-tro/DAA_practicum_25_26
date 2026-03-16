#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

int n, m, p, a[MAX], sum;

int main()
{
	cin >> n >> m >> p;
	for(int i = 0; i < n; i++)cin >> a[i];
	
	sort(a, a + n);
	for(int i = 0; i < m; i++)sum -= a[i];
	for(int i = m; i < n; i++)sum += a[i];
	
	cout << sum << endl;
	
	return 0;
}
