# include <bits/stdc++.h>
using namespace std;
int const maxn = 2e6+5;
int a[maxn];
void build(int v)
{
	int par = (v - 1) / 2;
	if (a[par] < a[v]) {
		swap(a[par], a[v]);
		build(par);
	}
}
void soak(int v, int n)
{
	int child1 = 2*v + 1;
	int child2 = 2*v + 2;
	if (child1 > n) return ;
	if (child2 > n) {
		if (a[child1] > a[v]) {
			swap(a[child1], a[v]);
		}
		return ;
	}
	else {
		int greaterChild = child2;
		if (a[child1] >= a[child2])greaterChild = child1;
		if (a[greaterChild] > a[v]) {
			swap(a[greaterChild], a[v]);
			soak(greaterChild, n);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		build(i);
	}

	// for(int i = 0; i < n; i++)
	// 	cout << a[i] << " ";
	// cout << endl;

	for (int i = n-1; i > 0; i--)
	{
		swap(a[i], a[0]);
		soak(0, i-1);
	}

	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

}