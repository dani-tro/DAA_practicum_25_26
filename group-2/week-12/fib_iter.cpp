#include <bits/stdc++.h>

using namespace std;

int fib(int n)
{
	if(n <= 1)return 1;
	int f = 1, f_prev = 1, tmp;
	for(int i = 2; i <= n; i++)
	{
		tmp = f_prev;
		f_prev = f;
		f = f + tmp;
	}
	return f;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	cout << fib(n) << endl;
	
	return 0;
}
