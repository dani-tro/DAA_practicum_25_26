#include <iostream>
using namespace std;
const int maxn = 1e5+10;

int a[maxn], n;
long long s;

void solve() {

    int l = 1, r = n;

    while (s >= min(l, n-r+1) && l < r) {
        
        if (l <= n-r+1) {
            s -= l;
            ++l;

        } else {

            s -= n-r+1;
            --r;

        } 

    }

    cout << r-l << '\n';

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