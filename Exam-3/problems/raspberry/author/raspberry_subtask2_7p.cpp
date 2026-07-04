#include<iostream>
#include<algorithm>
#define MAXN 500
#define MAXM 500
using namespace std;
int a[MAXN][MAXM];
int dp[MAXN][MAXM];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m ;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j] ;
        }
    }
    dp[0][m-1]=a[0][m-1];
    int max1=dp[0][m-1];
    for (int i=m-2; i>=0; i--) {
        dp[0][i]=a[0][i]+max1;
        max1=max(max1,dp[0][i]);
    }
    long long int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            //cout << dp[i][j] << " ";
            ans+=dp[i][j];
        }
        //cout << endl ;
    }
    cout << ans ;
    cout << endl ;
    return 0;
}
