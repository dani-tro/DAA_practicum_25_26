#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;

long long a[maxn], n;
long long s;

void solve() {

    long long minval = 1e9+1, maxval = 0;
    long long mincnt, maxcnt;
    
   for (int i = 1 ; i <= n && s > 0; ++i) {

        minval = 1e9+1;
        maxval = 0;
        mincnt = maxcnt = 0;

        for (int j = 1 ; j <= n ; ++j) {

            if (a[j] == minval) ++mincnt;
            if (a[j] < minval) minval = a[j], mincnt = 1;
            if (a[j] == maxval) ++maxcnt;
            if (a[j] > maxval) maxval = a[j], maxcnt = 1;

        }

        if (minval == maxval || s < min(mincnt, maxcnt)) break;

        if (mincnt <= maxcnt) {

            for (int i = 1 ; i <= n ; ++i)
                if (a[i] == minval) ++a[i];

            s -= mincnt;

        } else {

            for (int i = 1 ; i <= n ; ++i)
                if (a[i] == maxval) --a[i];

            s -= maxcnt;
            
        }

    }

    maxval = 0, minval = 1e9+1;
    for (int i = 1 ; i <= n ; ++i)  {

        maxval = max(maxval, a[i]);
        minval = min(minval, a[i]);

    }

    cout << maxval - minval << '\n';

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