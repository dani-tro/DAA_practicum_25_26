#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAXN = 1e5 + 10;
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
	
	priority_queue <array<int, 2>, vector <array<int, 2> >, greater <array <int, 2> > > pq;
	
	for (int i = 0; i < n; i++) dist[i] = -1;
	
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int s;
		cin >> s;
		dist[s] = 0;
		pq.push({0, s});
	}
	
	while (!pq.empty()) {
		int x = pq.top()[1];
		if (pq.top()[0] != dist[x]) {
			pq.pop();
			continue;
		}
		pq.pop();
		
		for (auto i : v[x]) {
			if (dist[i.to] == -1 || dist[x] + i.w < dist[i.to]) {
				dist[i.to] = dist[x] + i.w;
				pq.push({dist[i.to], i.to});
			}
		}
	}
	
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int x; cin >> x;
		cout << dist[x] << endl;
	}
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
/*
8 12
0 1 15
5 1 4
6 5 5
4 6 7
7 4 8
3 5 10
2 0 2
5 1 9
5 4 5
4 1 8
6 2 10
2 6 7
2
4 6
3
3
0
2
*/
