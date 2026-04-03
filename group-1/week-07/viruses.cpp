#include <bits/stdc++.h>

using namespace std;

bool A[100][100];

void dfs(int x, int y, int n, int m)
{
    if (x >= n || x < 0 || y >= m || y < 0) return;
    if (A[x][y] == 1) return;
    A[x][y] = 1;
    dfs(x + 1, y, n, m);
    dfs(x - 1, y, n, m);
    dfs(x, y + 1, n, m);
    dfs(x, y - 1, n, m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int a, b;
        cin >> a >> b;
        A[a - 1][b - 1] = 1;
    }
    int cnt = 0;
    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < m; ++y)
        {
            if (!A[x][y]) 
            {
                cnt++;
                dfs(x, y, n, m);
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}

