#include <iostream>
using namespace std;

const int nmax = 100;

int r[nmax+1];
long long m[nmax+1][nmax+1];
int n;

void input(){
  cin >> n;
  for (int i=0; i<=n; i++)
    cin >> r[i];
}

int main(){
  int j;
  input();
  for (int i=1;i<=n;i++)
    m[i][i] = 0;
  for (int k=1;k<n;k++){
    for (int i=1; i<=n-k; i++){
      j=i+k;
      m[i][j]= m[i][i]+m[i+1][j]+r[i-1]*r[i]*r[j];
      for (int p=i+1;p<j;p++)
        m[i][j]=min(m[i][j], (m[i][p]+m[p+1][j]+r[i-1]*r[p]*r[j]));
    }
  }

  cout << m[1][n]<< endl;

  return 0;
}
