# include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int cnt[maxn];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int a;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		cnt[a] ++;
	}

	for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < cnt[i]; j++)
			cout << i << " ";
	}
	cout << endl;
}