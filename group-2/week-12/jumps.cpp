# include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;

int a[maxn];
int dp[maxn][2];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[1][0] = a[1];
    dp[1][1] = a[1];
    
    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])+a[i];
        dp[i][1] = dp[i-2][0] + a[i];
    }
    
    int ans = -INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    cout << ans << endl;
}
