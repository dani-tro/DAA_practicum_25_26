#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 2e3 + 5e2 + 10;
const int MAXM = 5e3 + 10;
const int INF = 5e12 + 10;
struct Edge {
	int from;
	int to;
	int w;
};

Edge ed[MAXM];
vector <int> opposite[MAXN];
bool ableToReachN[MAXN];
int dist[MAXN];

void dfs(int x) {
	ableToReachN[x] = true;
	for (auto i : opposite[x]) {
		if (ableToReachN[i]) continue;
		dfs(i);
	}
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> ed[i].from >> ed[i].to >> ed[i].w;
		opposite[ed[i].to].push_back(ed[i].from);
	}
	
	dfs(n);
	for (int i = 2; i <= n; i++) dist[i] = -INF;
	dist[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[ed[j].from] == -INF) continue;
			dist[ed[j].to] = max(dist[ed[j].to], dist[ed[j].from] + ed[j].w);
		}
	}
	bool posCycle = false;
	for (int j = 0; j < m; j++) {
		if (dist[ed[j].from] == -INF) continue;
		if (dist[ed[j].to] < dist[ed[j].from] + ed[j].w && ableToReachN[ed[j].to]) {
			posCycle = true;
			break;
		}
	}
	
	if (posCycle) cout << -1 << endl;
	else cout << dist[n] << endl;
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
