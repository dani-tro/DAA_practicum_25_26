#include<iostream>
#include<algorithm>
#define MAXN 500
#define MAXM 500
using namespace std;
int a[MAXN][MAXM],n,m;
int ans;
void rec (int x, int y, int path) {
    path+=a[x][y];
    if ((x==n-1)&&(y==m-1)) {
        ans=max(ans,path);
        return ;
    }
    for (int i=x; i<n; i++) {
        for (int j=y; j<m; j++) {
            if ((i==x)&&(j==y)) continue;
            rec(i,j,path);
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m ;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j] ;
        }
    }

    long long int sum=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            ans=a[i][j];
            rec(i,j,0);
            //cout << ans << " ";
            sum+=ans;
        }
        //cout << endl ;
    }
    cout << sum ;
    cout << endl ;
    return 0;
}
