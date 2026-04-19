#include <bits/stdc++.h>

using namespace std;

#define MAX 11000

int n, a, b, arr[MAX], sum, ansl, anscnt, currl;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if(a > b)swap(a, b);
		arr[a]++;
		arr[b]--;
	}
	
	for(int i = 0; i <= 10001; i++)
	{
		sum += arr[i];
		if(sum > 0)
		{
			currl++;
		}	
		else
		{
			ansl = max(ansl, currl);
			if(currl > 0)anscnt++;
			currl = 0;
		}
	}
	
	cout << anscnt << " " << ansl << endl;
	
	return 0;
}
