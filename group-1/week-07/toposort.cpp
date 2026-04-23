#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 10;
vector <int> v[MAXN];
int in[MAXN]; // степен на влизане (in[x] = колко ребра влизат в връх x)

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		in[y]++;
	}
	
	priority_queue <int, vector <int>, greater <int> > q; // q e минимална приоритетна опашка
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) q.push(i);
	}
	
	vector <int> ans;
	while (!q.empty()) {
		int x = q.top();
		q.pop();
		ans.push_back(x);
		
		for (auto i : v[x]) {
			in[i]--;
			if (in[i] == 0) q.push(i);
		}
	}
	if (ans.size() < n) cout << "Sandro fails.\n";
	else {
		for (auto i : ans) cout << i << ' ';
		cout << endl;
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
