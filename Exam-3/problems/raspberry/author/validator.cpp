#include<iostream>
#include<algorithm>
#include<assert.h>
#define MAXN 500
#define MAXM 500
using namespace std;
int a[MAXN][MAXM];
int dp[MAXN][MAXM],max1[MAXN][MAXM];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    assert(cin >> n >> m );
    assert((1<=n)&&(n<=500));
    assert((1<=m)&&(m<=500));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            assert(cin >> a[i][j] );
            assert((-1000<=a[i][j])&&(a[i][j]<=1000));
        }
    }
    //assert(((n==1)&&(m==1))||(a[n-1][m-1]>0));
    char temp; assert(!(cin >> temp ));
    dp[n-1][m-1]=a[n-1][m-1];
    max1[n-1][m-1]=dp[n-1][m-1];
    for (int j=m-2; j>=0; j--) {
        dp[n-1][j]=max1[n-1][j+1];
        if (dp[n-1][j]<0) dp[n-1][j]=0;
        dp[n-1][j]+=a[n-1][j];
        max1[n-1][j]=max(max1[n-1][j+1],dp[n-1][j]);
    }
    for (int i=n-2; i>=0; i--) {
        dp[i][m-1]=max1[i+1][m-1];
        if (dp[i][m-1]<0) dp[i][m-1]=0;
        dp[i][m-1]+=a[i][m-1];
        max1[i][m-1]=max(max1[i+1][m-1],dp[i][m-1]);
    }
    for (int i=n-2; i>=0; i--) {
        for (int j=m-2; j>=0; j--) {
            dp[i][j]=max(max1[i+1][j],max1[i][j+1]);
            if (dp[i][j]<0) dp[i][j]=0;
            dp[i][j]+=a[i][j];
            max1[i][j]=max({dp[i][j], max1[i+1][j], max1[i][j+1]});
        }
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
