#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
	int a;
	stack <int> st;
	while (cin >> a) {
		st.push(a);
	}
	
	while (!st.empty()) {
		int a = st.top(); st.pop();
		cout << fixed << setprecision(6) << sqrt(a) << endl;
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
}
