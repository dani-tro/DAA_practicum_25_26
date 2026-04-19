//Task: expedition
//Author: Kinka Kirilova-Lupanova

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<pair<ll, ll> > a;
ll n, m, c, t, best, ans;
int main()
{
  cin >> n >> m >> c;
  a.resize(n);
  for (int i = 0; i < n; i++)
     cin >> a[i].first >> a[i].second;
  for (int i = 0; i < m; i++)
    {
     best = -1;
     cin >> t;
     for (int j = 0; j < n; j++)
       {
        ans = llabs(a[j].first - t) * c + a[j].second;
        if (ans < best || best == -1)
        best = ans;
       }
     cout << best << "\n";
   }
}
