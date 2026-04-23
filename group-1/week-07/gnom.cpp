#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

struct Edge {
	int to;
	int y;
};
vector <Edge> v[MAXN];
int cost[MAXN];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> cost[i];
	
	for (int i = 0; i < m; i++) {
		int a, x, y;
		cin >> a >> x >> y;
		v[x].push_back({a, y});
		v[y].push_back({a, x});
	}
	priority_queue <array <int, 2>, vector <array <int, 2> >, greater <array <int, 2> > > q;
	for (int i = 1; i <= n; i++) {
		q.push({cost[i], i});
	}
	
	while (!q.empty()) {
		int x = q.top()[1];
		if (cost[x] < q.top()[0]) {
			q.pop();
			continue;
		}
		q.pop();
		
		for (auto i : v[x]) {
			if (cost[i.to] > cost[i.y] + cost[x]) {
				cost[i.to] = cost[i.y] + cost[x];
				q.push({cost[i.to], i.to});
			}
		}
	}
	cout << cost[1] << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
/*
5 3
5 0 1 2 5
5 2 3
4 2 3
1 4 5
*/
