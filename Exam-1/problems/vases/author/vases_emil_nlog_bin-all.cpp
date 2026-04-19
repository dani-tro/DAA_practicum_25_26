#include <iostream>
#include <algorithm>

const int MAX_N = 1e7;

int n;
int h;

int hs[MAX_N];

int ans;

void input()
{
    std::cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        std::cin >> hs[i];
    }
}

void output()
{
    std::cout << ans << std::endl;
}

bool check(int w)
{
    int sum = 0;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr == 0)
        {
            sum += hs[i];
            if (sum > h) return false;
        }
        curr++;
        if (curr == w) curr = 0;
    }

    return true;
}

void solve()
{
    std::sort(hs, hs + n);
    std::reverse(hs, hs + n);

    int l = 0;
    int r = n;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m;
    }

    ans = r;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    input();
    solve();
    output();

    return 0;
}