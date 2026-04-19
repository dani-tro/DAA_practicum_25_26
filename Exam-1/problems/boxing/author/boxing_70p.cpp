#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <vector>

typedef long long llong;
const int MAXN = 10000000 + 10;
const int INF  = 1e9;

int n;
llong k;
int a[MAXN];
llong prefix[MAXN];
int x, y, z, m;

llong calcSum(int l, int r)
{
    return prefix[r] - prefix[l - 1];
}

llong check(int l, int r)
{
    llong left = 0, right = 0;
    int splitL = l - 1, splitR = r + 1, split;
    while (splitL < splitR - 1)
    {
        split = (splitL + splitR) / 2;
        left = calcSum(l, split);
        right = calcSum(split + 1, r);
        if (left < right) splitL = split;
        else splitR = split;
    }

    return std::max(calcSum(l, splitL), calcSum(splitR + 1, r)); 
}

void solve()
{
    for (int i = 1 ; i <= n ; ++i)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }

    int lPtr = 0;
    llong ans = INF;
    for (int rPtr = 1 ; rPtr <= n ; rPtr++)
    {
        while (lPtr + 1 <= rPtr && check(lPtr + 1, rPtr) >= k)
        {
            lPtr++;
        }

        if (check(lPtr, rPtr) >= k) ans = std::min(ans, (llong) (rPtr - lPtr + 1));
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

int main()
{
    fastIO();
    input();
    solve();

    return 0;
}
