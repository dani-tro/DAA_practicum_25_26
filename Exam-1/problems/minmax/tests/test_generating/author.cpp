#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;

int a[maxn], n;
pair < long long, long long > b[maxn];
long long s;

void solve() {

    sort(a+1, a+n+1);

    int cnt = 1;
    b[1] = {a[1], 1};

    for (int i = 2 ; i <= n ; ++i) {

        if (a[i] == a[i-1]) ++b[cnt].second;
        else b[++cnt] = {a[i], 1};

    }

    int l = 1, r = cnt;

    while (s >= 1 && l < r) {

        if (b[l].second < b[r].second || (b[l].second == b[r].second && (b[l+1].first - b[l].first) <= (b[r].first - b[r-1].first))) {

            if (s < (b[l+1].first - b[l].first) * b[l].second) {

                b[l].first += s / b[l].second;
                break;

            }

            s -= (b[l+1].first - b[l].first) * b[l].second;
            b[l+1].second += b[l].second;
            ++l;

        } else {

            if (s < (b[r].first - b[r-1].first) * b[r].second) {

                b[r].first -= s / b[r].second;
                break;

            }
            
            s -= (b[r].first - b[r-1].first) * b[r].second;
            b[r-1].second += b[r].second;
            --r;

        }
        
    }

    if (l >= r) cout << 0 << '\n';
    else cout << b[r].first - b[l].first << '\n'; 

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