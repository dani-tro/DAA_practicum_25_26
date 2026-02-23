#include <bits/stdc++.h>

using namespace std;

#define MAX 1100

int n, a[MAX];

void selectionSort()
{
	for(int i = 0; i < n - 1; i++)
	{
		int minIdx = i;
		for(int j = i; j < n; j++)
		{
			if(a[minIdx] > a[j]) 
			{
				minIdx = j;
			}
		}
		swap(a[i], a[minIdx]);

		for(int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
	cout << endl;
	}
	return;
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

	selectionSort();


	return 0;	
}