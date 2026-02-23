# include <bits/stdc++.h>
using namespace std;
long long a[25][25], b[25][25], c[25][25];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			// cout << i << " " << j << " : " << a[i][j] << endl;
		}
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < k; j++)
			{
				cin >> b[i][j];
				// cout << i << " " << j << " : " << b[i][j] << endl;
			}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int t = 0; t < m; t++)
			{
				c[i][j] += a[i][t]*b[t][j];
				// cout << i << " " << j << " : " << c[i][j] << endl;
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	
}