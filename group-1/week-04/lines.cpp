#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;

struct Event {
	int x;
	int type; // +1 за начало, -1 за край
	friend bool operator < (const Event& a, const Event& b) {
		if (a.x != b.x) return a.x < b.x;
		return a.type > b.type;
	}
};

struct Line{
	int x1, y1, x2, y2;
};

Event e[2 * MAXN];
Line l[MAXN];
int n;
int ans;

void f() {
	sort(e, e + 2*n);
	int cnt = 0;
	for (int i = 0; i < 2*n; i++) {
		cnt += e[i].type;
		ans = max(ans, cnt);
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i].x1 >> l[i].y1 >> l[i].x2 >> l[i].y2;
		if (l[i].x1 > l[i].x2) swap(l[i].x1, l[i].x2);
		if (l[i].y1 > l[i].y2) swap(l[i].y1, l[i].y2);
		
		e[i * 2] = {l[i].x1, 1};
		e[i * 2 + 1] = {l[i].x2, -1};
	}
	f();
	
	for (int i = 0; i < n; i++) {
		e[i * 2] = {l[i].y1, 1};
		e[i * 2 + 1] = {l[i].y2, -1};
	}
	f();
	
	cout << ans << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
}
