#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int to;
	int w;
};

const int MAXN = 2e5 + 10;

vector <Edge> v[MAXN];
queue <int> q[2];

int dist[MAXN];

void solve () {
	int n, a, b, x, y;
	cin >> n >> a >> b;
	while (cin >> x >> y) {
		v[x].push_back({y, 0});
		v[y].push_back({x, 1});
	}
	int i0 = 0, i1 = 1;
	for (int i = 1; i <= n; i++) dist[i] = n + 1;
	q[0].push(a); dist[a] = 0;
	
	int d = 0;
	while (!q[i0].empty()) {
	
		while (!q[i0].empty()) {
			int x = q[i0].front();
			q[i0].pop();
			if (dist[x] != d) continue;
			
			for (auto i : v[x]) {
				if (dist[i.to] > d + i.w) {
					dist[i.to] = d + i.w;
					if (i.w == 0) q[i0].push(i.to);
					else q[i1].push(i.to);
				} 
			}
		}
		swap(i0, i1);
		d++;
	}
	
	if (dist[b] == n + 1) cout << "X\n";
	else cout << dist[b] << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
