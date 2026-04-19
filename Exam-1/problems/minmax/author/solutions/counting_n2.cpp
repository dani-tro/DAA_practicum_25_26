#include <iostream>
using namespace std;
const int maxn = 1e5+10, maxnum = 1e6+10;

int a[maxn], cnt[maxnum], n;
long long s;

void solve_n2() {

    long long minval = 1e9+1, maxval = 0;
    long long mincnt, maxcnt;
    
    for (int i = 1 ; i <= n && s > 0 ; ++i) {

        minval = 1e9+1;
        maxval = 0;

        for (int j = 1 ; j <= n ; ++j) {

            if (a[j] == minval) ++mincnt;
            if (a[j] < minval) minval = a[j], mincnt = 1;
            if (a[j] == maxval) ++maxcnt;
            if (a[j] > maxval) maxval = a[j], maxcnt = 1;

        }

        if (minval == maxval) break;

        if (mincnt <= maxcnt) {

            long long min2 = 1e9+1;
            for (int j = 1 ; j <= n ; ++j)
                if (a[j] < min2 && a[j] != minval) min2 = a[j];

            if (s < mincnt * (min2-minval)) {

                cout << maxval - (minval + s/mincnt) << '\n';
                return;

            }

            s -= mincnt * (min2-minval);

            for (int j = 1 ; j <= n ; ++j)
                if (a[j] == minval) a[j] = min2;

        } else {

            long long max2 = 0;
            for (int j = 1 ; j <= n ; ++j)
                if (a[j] > max2 && a[j] != maxval) max2 = a[j];

            if (s < maxcnt * (maxval-max2)) {

                cout << (maxval - s/maxcnt) - minval << '\n';
                return;

            }

            s -= maxcnt * (maxval-max2);

            for (int j = 1 ; j <= n ; ++j)
                if (a[j] == maxval) a[j] = max2;

        }

    }

    maxval = 0, minval = 1e9+1;
    for (int i = 1 ; i <= n ; ++i)  {

        maxval = max(maxval, (long long)a[i]);
        minval = min(minval, (long long)a[i]);

    }

    cout << maxval - minval << '\n';

}

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

bool counting() {

    for (int i = 1 ; i <= n ; ++i)
        if (a[i] > 1e6) return 0;
    return 1;

}

int main () {

    fast_io();
    read();
    if (counting()) solve();
    else solve_n2();

    return 0;

}