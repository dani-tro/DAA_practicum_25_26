# include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+5;
int a[maxn];
mt19937 rng(834);
int partition(int l, int r, int p)
{
	int uk1 = l, uk2 = r;
	int x = a[p];
	swap(a[p], a[r]);
	while(uk1 < uk2)
	{
		if (a[uk1] >= x && a[uk2] < x)
		{
			swap (a[uk1], a[uk2]);
		}
		if (a[uk1] < x) uk1++;
		if (a[uk2] >= x) uk2 --;
	}
	if (a[uk1] < x) uk1 ++;
 	swap(a[uk1], a[r]);
	// cout << x << " : " << uk1 << " " << uk2 << endl;
	// for(int i = l; i <= r; i++)
	// 	cout << a[i] << " ";
	// cout << endl;
	return uk1;
}
void quickSort(int l, int r)
{
	if (r <= l) return ;
	// int p = l;
	int p = rng()%(r - l + 2) + l;
	int id = partition(l, r, p);
	quickSort(l, id-1);
	quickSort(id+1, r);
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	quickSort(0, n-1);
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
}