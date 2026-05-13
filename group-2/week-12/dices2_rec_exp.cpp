#include <bits/stdc++.h>

using namespace std;

int cnt;

#define MOD 1000000007

void rec(int sum, int dices_left)
{	
	if(sum < 0 || dices_left < 0)return ;
	if(sum == 0 && dices_left == 0)
	{
		cnt++;
		cnt %= MOD;
		return ;
	}
	
	for(int i = 1; i <= 6; i++)
	{
		rec(sum - i, dices_left - 1);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, s;
	cin >> n >> s;
	
	rec(s, n);
	
	cout << cnt << endl;
	return 0;
}
