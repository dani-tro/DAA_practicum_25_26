# include <bits/stdc++.h>
using namespace std;
struct Edge {
	int u, v, w;
	bool taken = false;
	int id = 0;
	int initial_id = 0;
	bool operator < (const Edge &e) const {
		return w > e.w;
	}
};
vector <Edge> edges;
const int N = 1e6 + 5;
int comp[N];
int sz[N];
struct DSU {
	void init(int n) {
		for (int i = 0; i < n; i++) {
			comp[i] = i;
			sz[i] = 1;
		}
	}
	int find(int u) {
		if (comp[u] == u) return u;
		return comp[u] = find(comp[u]);
	}
	bool merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return false;
		if (sz[u] < sz[v]) swap(u, v);
		comp[v] = u;
		sz[u] += sz[v];
		return true;
	}
};
DSU dsu;
int ANS[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w, false, 0, i});
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= k; i++) {
		dsu.init(n + 1);
		long long ans = 0;
		for (auto &e : edges) {
			if (e.taken) {
				continue;
			} 
			if (dsu.merge(e.u, e.v)) {
				e.taken = true;
				ANS[e.initial_id] = i;
				ans += e.w;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << ANS[i] << endl;
	}
}