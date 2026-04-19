#include <bits/stdc++.h>
using namespace std;

long long a[100002];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    long long s; cin >> s;

    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    a[0] = a[1];
    a[n+1] = a[n];

    vector<pair<int, long long>> v;
    int start = 1;
    for (int i = 1; i <= n; i++) {
        if (i == n || a[i] != a[i+1]) {
            v.push_back({i, a[i+1]-a[i]});
            v.push_back({n-start+1, a[start]-a[start-1]});

            start = i+1;
        }
    }

    sort(v.begin(), v.end());

    long long ans = a[n]-a[1];
    for (auto [br, diff]: v) {
        ans -= min(s/br, diff);
        s -= br*min(s/br, diff);
    }
    cout << max(ans, 0ll) << endl;

    return 0;
}
