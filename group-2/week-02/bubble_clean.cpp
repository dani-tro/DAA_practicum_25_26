# include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j <= n - i; j++)
			if(a[j] > a[j + 1]) 
				swap(a[j], a[j + 1]);

		for(int j = 1; j <= n; j++) cout << a[j] << " ";
		cout << endl;
	}
}