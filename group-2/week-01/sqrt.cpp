#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long a;
	
	stack<int> s;
	
	while(cin >> a)
	{
		s.push(a);
	}
	
	while(!s.empty())
	{
		cout << fixed << setprecision(6) << sqrt(s.top()) << endl;
		s.pop();
	}
	
	return 0;
}
