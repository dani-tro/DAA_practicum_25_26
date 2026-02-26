#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e4 + 10;
int a[MAXN];

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        int s = 0;
        for (int r = l; r <= n; r++) {
            s += a[r];
            if ((r - l + 1) % 2 == 0) continue;
            ans += s;
        }
    }
    cout << ans << endl;
    return 0;
}
