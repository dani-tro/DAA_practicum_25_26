#include <iostream>
using namespace std;
const int maxn = 1e5+10, maxnum = 1e6+10;

int a[maxn], cnt[maxnum], n;
long long s;

void solve() {

    for (int i = 1 ; i <= n ; ++i)
        ++cnt[a[i]];

    int l = 1, r = maxnum;

    while (s >= min(cnt[l], cnt[r]) && l < r) {
        
        if (cnt[l] <= cnt[r]) {

            s -= cnt[l];
            cnt[l+1] += cnt[l];
            ++l;

        } else {

            s -= cnt[r];
            cnt[r-1] += cnt[r];
            --r;

        }

    }
    
    cout << r - l << '\n';

}

void fast_io() {

    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

}

void read() {

    cin >> n >> s;
    for (int i = 1 ; i <= n ; ++i)
        cin >> a[i];

}

int main () {

    fast_io();
    read();
    solve();

    return 0;

}