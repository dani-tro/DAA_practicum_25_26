#include<iostream>
using namespace std;

const int N_max=210;
int a[N_max], b[N_max], aa[N_max], bb[N_max];
int n;
int s;

//int b[N_max];

int c=0;

void f(int s, int i)
{
  //cout << "s=" << s << " i=" << i << endl;
  if(i==n)
    {c++;
     //for(int j=0;j<n;j++) cout << b[j] << " ";
     //cout << endl;
     return;
    }
  if(i==n-1)
  {
   if(s%a[i]==0)
   {
     //b[i]=s/a[i];
     f(0,i+1);
   }
  }
  else
  {
   int m=s/a[i];
   if(m>b[i]) m=b[i];
   for(int k=0;k<=m;k++)
   {
    //b[i]=k;
    f(s-k*a[i],i+1);
   }
  }
}

int main()
{
  cin >> s >> n;
  for(int i=0;i<n;i++) cin >> aa[i];
  for(int i=0;i<n;i++) cin >> bb[i];

  int j=-1;
  for(int i=0;i<n;i++)
  {
    if(aa[i]!=0)
     {j++;a[j]=aa[i];b[j]=bb[i];aa[i]=0;
      for(int k=i+1;k<n;k++)
       if(aa[k]==a[j]){aa[k]=0;b[j] += bb[k];}
     }
  }

  n=j+1;

  f(s,0);
  cout << c << endl;
}
