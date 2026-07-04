#include <iostream>
using namespace std;

const int nmax = 100;

int r[nmax+1];
int n;

void input(){
  cin >> n;
  for (int i=0; i<=n; i++)
    cin >> r[i];
}

long long solve(int i, int j){
  long long s;
  if (i == j)
    s = 0;
  else {
    if (i+1 == j)
      s = r[i-1]*r[i]*r[j];
    else{
      s = 1000000000000000000;
      for (int k=i;k<j;k++)
        s = min(s,solve(i,k)+solve(k+1,j)+r[i-1]*r[k]*r[j]);
    }
  }
  return s;
}

int main(){
  input();
  cout << solve(1,n)<< endl;

  return 0;
}
