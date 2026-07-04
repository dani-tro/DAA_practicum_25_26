# include <iostream>

using namespace std;
const int MAXN = 505;
int a[MAXN][MAXN];
long long dp[MAXN][MAXN];
int n,m;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
}

long long solve_slow(){
    long long ans = 0;
    for(int i = n; i > 0; i--)
        for(int j = m; j > 0; j--)
        {
            dp[i][j] = a[i][j];
            long long maxs = 0;
            for(int t1 = i; t1 <= n; t1++)
                for(int t2 = j; t2 <= m; t2++){
                    if(i == t1 && j == t2) continue;
                    maxs = max(maxs, dp[t1][t2]);
                }
            dp[i][j] += maxs;
            //cout << i << " " << j << " " << dp[i][j] << endl;
            ans += dp[i][j];
        }
    return ans;
}

long long solve_mid(){
    long long ans = 0;
    for(int i = n; i > 0; i--)
        for(int j = m; j > 0; j--)
        {
            //dp[i][j] = a[i][j];
            long long maxs = 0;
            for(int t1 = i; t1 <= n; t1++)
                    maxs = max(maxs, dp[t1][j]);
            maxs = max(maxs, dp[i][j+1]);
            dp[i][j] = a[i][j] + maxs;
            //cout << i << " " << j << " " << dp[i][j] << endl;
            ans += dp[i][j];
            dp[i][j] = max(dp[i][j], dp[i][j+1]);
        }
    return ans;
}

int main()
{
    fastIO();
    input();
    cout << solve_mid() << endl;
}