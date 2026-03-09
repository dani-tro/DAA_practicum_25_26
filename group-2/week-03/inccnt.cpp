# include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6+5;
long long a[maxn];
long long b[maxn];
long long merge(long long l1, long long r1, long long l2, long long r2)
{
	long long p1 = l1;
	long long p2 = l2;
	long long i = 0;
	long long inv = 0;
	while(p1 <= r1 && p2 <= r2)
	{
		if (a[p1] < a[p2])
		{
			b[i] = a[p1];
			i++;p1++;
			inv += p2 - l2;
		}
		else {
			b[i] = a[p2];
			i++;p2++;
		}
	}
	while(p1 <= r1)
	{
		b[i] = a[p1];
		i++;p1++;
		inv += p2 - l2;
	}
	while(p2 <= r2)
	{
		b[i] = a[p2];
		i++;p2++;
	}

	for (long long j = 0; j < i; j++)
	{
		a[l1+j] = b[j];
	}

	return inv;
}
long long mergeSort(long long l, long long r)
{
	if (l == r) return 0;
	long long mid = (r+l)/2;
	long long inv = mergeSort(l, mid);
	inv += mergeSort(mid+1, r);
	inv += merge(l, mid, mid+1, r);
	return inv;
}
int main()
{
	long long n;
	cin >> n;
	for(long long i = 0; i < n; i++)
		cin >> a[i];

	long long ans = mergeSort(0, n-1);
	cout << ans << endl;
}