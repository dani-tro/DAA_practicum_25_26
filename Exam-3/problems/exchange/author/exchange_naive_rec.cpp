#include<iostream>
using namespace std;

const int N_max=210;
const long long mod = 1e9 + 7;
long long int a[N_max], b[N_max], aa[N_max], bb[N_max];
int n;
const int S_max=50002;
long long int s;

long long int t[S_max][N_max];

long long int f(int s, int i)
{
  //cout << "s=" << s << " i=" << i << endl;
  if(t[s][i]>-1) return t[s][i];
  if(i==n-1)
   {
    t[s][i]=0;
    if(s%a[i]==0)
     if(s/a[i]<=b[i]) t[s][i]=1;
    return t[s][i];
   }
  else
  {
   long long int bb=0;
   long long int m=s/a[i];
   if(m>b[i]) m=b[i];
   for(int k=0;k<=m;k++)
   {
    //b[i]=k;
    bb = (bb + f(s-k*a[i],i+1)) % mod;
   }
   t[s][i]=bb;
   return bb;
  }
}

int main()
{
  cin >> s >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  
  for(int i=0;i<=s;i++)
  for(int j=0;j<n;j++)
  t[i][j]=-1;

  long long int r=f(s,0);
  cout << r << endl;
}
