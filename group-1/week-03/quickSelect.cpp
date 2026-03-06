#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 10;
int a[MAXN], k;

mt19937 myRand(6769420);

int randIdx(int l, int r) {
	return l + myRand() % (r - l + 1);
}

int quickSelect(int l, int r) {
	if (l >= r) return a[l];
	
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
	
	if (i == k) return a[i];
	if (i < k) return quickSelect(i + 1, r);
	return quickSelect(l, i - 1);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	cout << quickSelect(1, n) << endl;
	return 0;
}
