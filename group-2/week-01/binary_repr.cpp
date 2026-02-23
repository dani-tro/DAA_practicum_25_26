# include <bits/stdc++.h>
using namespace std;
void to_binary(int x)
{
	int cnt = 0;
	while(x != 0)
	{
		cnt += x%2;
		x /= 2;
	}
	cout << cnt << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, x;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> x;
		to_binary(x);
	}
}