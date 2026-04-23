#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5 + 10;
const int INF = 1e14;

struct Edge{
	int to;
	int cost;
	int t;
};

int dist[MAXN];
vector <Edge> v[MAXN];
int n, m, k;

bool p(int c) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[1] = 0;
	priority_queue <array<int, 2>, vector <array<int, 2> >, greater <array <int, 2> > > q;
	q.push({0, 1});
	
	while (!q.empty()) {
		int x = q.top()[1];
		if (q.top()[0] != dist[x]) {
			q.pop();
			continue;
		}
		q.pop();
		
		for (auto i : v[x]) {
			if (i.cost > c) continue;
			if (dist[x] + i.t < dist[i.to]) {
				dist[i.to] = dist[x] + i.t;
				q.push({dist[i.to], i.to});
			}
		}
	}
	
	return dist[n] <= k;
}

void solve() {
	cin >> n >> m >> k;
	int maxP = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[a].push_back({b, c, d});
		maxP = max(maxP, c);
	}
	
	int l, r, mid;
	l = 0; r = maxP;
	while (l <= r) {
		mid = (l + r) / 2;
		if (p(mid)) r = mid - 1;
		else l = mid + 1;
	}
	
	if (l == maxP + 1) cout << -1 << endl;
	else cout << l << endl;
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
