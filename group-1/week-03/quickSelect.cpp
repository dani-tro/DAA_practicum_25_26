#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 10;
int a[MAXN];

mt19937 myRand(6769420);

int randIdx(int l, int r) {
	return l + myRand() % (r - l + 1);
}

void quickSort(int l, int r) {
	if (l >= r) return;
	
	int idx = randIdx(l, r);
	int pivot = a[idx];
	swap(a[idx], a[r]);
	
	int i = l, j = r - 1;
	while (i <= j) {
		if (a[i] < pivot) i++;
		else if (a[j] >= pivot) j--;
		else {
			swap(a[i], a[j]);
			i++; j--;
		}
	}
	
	swap(a[i], a[r]);
	quickSort(l, j);
	quickSort(i + 1, r);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	quickSort(1, n);
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << endl;
	return 0;
}
