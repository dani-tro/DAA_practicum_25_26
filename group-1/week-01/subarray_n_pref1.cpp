#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 10;

long long a[MAXN];
long long pref[MAXN], pref1[MAXN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    
    if (n == 1) {
        cout << a[1] << endl;
        return 0;
    }
    
    pref1[1] = pref[1]; pref1[2] = pref[2];
    for (int i = 3; i <= n; i++) {
        pref1[i] = pref1[i - 2] + pref[i];
    }
    
    long long ans = 0;
    for (long long r = 1; r <= n; r++) {
        ans += pref[r] * ((r - 1) / 2 + 1);
        ans -= pref1[r - 1];
    }
    cout << ans << endl;
    return 0;
}
