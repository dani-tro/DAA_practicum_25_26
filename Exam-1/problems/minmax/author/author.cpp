#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;

long long a[maxn], n;
long long s;

void solve() {

    sort(a+1, a+1+n);
    long long l = 1, r = n;

    while (l < r) {
        
        if (l <= (n-r+1)) {
            
            if (s < l*(a[l+1]-a[l])) {

                cout << a[r]-a[l] - s/l << '\n';
                return;

            }

            s -= l*(a[l+1]-a[l]);
            ++l;

        } else {

            if (s < (n-r+1)*(a[r]-a[r-1])) {

                cout << a[r]-a[l] - s/(n-r+1) << '\n';
                return;

            }

            s -= (n-r+1)*(a[r]-a[r-1]);
            --r;

        } 

    }

    if (l >= r) cout << 0 << '\n';
    else cout << a[r]-a[l] << '\n';

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