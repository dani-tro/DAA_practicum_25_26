#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e3 + 10;
struct Edge {
	int to;
	int w;
};

vector <Edge> v[MAXN];
int dist[MAXN];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	int s; cin >> s;
	for (int i = 0; i < n; i++) dist[i] = -1;
	dist[s] = 0;
	priority_queue <array<int, 2>, vector <array<int, 2> >, greater <array <int, 2> > > q;
	q.push({0, s});
	
	while (!q.empty()) {
		int x = q.top()[1];
		if (q.top()[0] != dist[x]) {
			q.pop();
			continue;
		}
		q.pop();
		
		for (auto i : v[x]) {
			if (dist[i.to] == -1 || dist[x] + i.w < dist[i.to]) {
				dist[i.to] = dist[x] + i.w;
				q.push({dist[i.to], i.to});
			}
		}
	}
	
	for (int i = 0; i < n; i++) cout << dist[i] << ' ';
	cout << endl;
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
