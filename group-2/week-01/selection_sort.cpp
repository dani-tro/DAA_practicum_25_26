// O(n^2)

#include <bits/stdc++.h>

using namespace std;

#define MAX 1100

int n, a[MAX];

void selection_sort()
{
	for(int i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		for(int j = i; j < n; j++)
		{
			if(a[min_idx] > a[j])
			{
				min_idx = j;
			}
		}
		swap(a[i], a[min_idx]);
		
		for(int j = 0; j < n; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	selection_sort();
	
	return 0;
}
