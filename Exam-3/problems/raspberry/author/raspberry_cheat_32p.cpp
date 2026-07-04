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
    for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            if ((i==n-1)&&(j==m-1)) dp[i][j]=a[i][j];
            else dp[i][j]=-1e9;
            for (int h=i; h<min(n,(n>100)?i+20:n); h++) {
                for (int k=((h==i)?j+1:j); k<min(m,(m>100)?j+20:m); k++) {
                    dp[i][j]=max(dp[i][j],a[i][j]+dp[h][k]);
                }
            }
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
