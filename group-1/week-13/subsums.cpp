#include <bits/stdc++.h>
using namespace std;

const int MAXS = 2e6 + 10;
const int offset = 1e6;

bool used[MAXS], isZero;

void solve() {
	int n; cin >> n;
	vector <int> sums;
	sums.push_back(0);
	used[offset] = true;
	
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		
		vector <int> temp;
		for (auto s : sums) {
			if (s + x == 0) isZero = true;
			if (!used[s + x + offset]) {
				temp.push_back(s + x);
				used[s + x + offset] = true;
			}
		}
		
		for (auto s : temp) sums.push_back(s);
	}
	cout << sums.size() - (!isZero) << endl; //пазим isZero, защото по условие подредиците са с дължина поне 1, а ние в началото добавихме 0 - сумата на празната подрециа
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}
