#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;

struct Point {
	int x;
	int type;
	friend bool operator < (Point a, Point b) {
		if (a.x != b.x) return a.x < b.x;
		return a.type > b.type;
	}
};

Point p[2 * MAXN];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		p[i * 2] = {a, 1};
		p[i * 2 + 1] = {b, -1};
	}
	sort(p, p + 2*n, [] (Point a, Point b) {
		if (a.x != b.x) return a.x < b.x;
		return b.type < a.type;
		});
	
	int currOpen = 0, ansBr = 0, ansMax = 0, currBeg = p[0].x;
	for (int i = 0; i < 2*n; i++) {
		currOpen += p[i].type;
		
		if (currOpen == 0) {
			ansMax = max(ansMax, p[i].x - currBeg);
			if (i < 2*n - 1) currBeg = p[i + 1].x;
			ansBr++;
		}
	}
	
	cout << ansBr << ' ' << ansMax << endl;
	return 0;
}
