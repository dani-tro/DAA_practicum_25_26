#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e7 + 10;
const int INF  = 1e9;

int n, k;
int a[MAXN];
int x, y, z, m;

void solve()
{
    int rPtr = 1, midPtr = 1, lSum = 0, rSum = 0, ans = INF;
    for (int lPtr = 1 ; lPtr <= n ; lPtr++)
    {
        while (midPtr <= n && lSum < k)
        {
        	lSum += a[midPtr];
        	rSum = max(0ll, rSum - a[midPtr]);
            midPtr++;
        }
        
        rPtr = max(rPtr, midPtr);
        while (rPtr <= n && rSum < k) {
        	rSum += a[rPtr];
        	rPtr++;
        }
        
        if (lSum >= k && rSum >= k) ans = min(ans, rPtr - lPtr);
        lSum -= a[lPtr];
    }
    if (ans == INF) ans = -1;

    std::cout << ans << '\n';
}

void input()
{
    std::cin >> n >> k;
    std::cin >> a[1] >> a[2] >> x >> y >> z >> m;
    for (int i = 3 ; i <= n ; ++i)
    {
        a[i] = (1LL * a[i - 2] * x + 1LL * a[i - 1] * y + z) % m;
    }
}

void fastIO()
{
    std::ios_base :: sync_with_stdio(0);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
}

signed main()
{
    fastIO();
    input();
    solve();

    return 0;
}
