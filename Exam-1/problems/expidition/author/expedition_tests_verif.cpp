//Task: expedition
//Author: Kinka Kirilova-Lupanova

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
pii active;
vector<pii> areas, aleft, aright;
ll c;
const ll inf=2e18;
const int inf1=1e9+1;


void err()
{
cout << 1/0;
}

int main()
{
 ios::sync_with_stdio(0);
 cin.tie(0);
 int n, m;
 cin >> n >> m >> c;

 if(n<1 || n > (int)1e5 || m<1 || m > (int)1e5 || c<1 || c > (int)1e9) err();

 if(cin.bad()) err();

 areas.resize(n);
 for (int i = 0; i < n; i++)
      cin >> areas[i].first >> areas[i].second;

 for (int i = 0; i < n; i++)
    if(areas[i].first < 0 || areas[i].first > (int)1e9
    || areas[i].second < 0 || areas[i].second > (int)1e9) err();

if(cin.bad()) err();


sort(areas.begin(), areas.end());
aleft.push_back(active=areas.front());
for (int i = 1; i < n; i++)
      if((areas[i].first - active.first) * c + active.second > areas[i].second)
          aleft.push_back(active=areas[i]);
aright.push_back(active=areas.back());
for (int i = n - 2; i >= 0; i--)
      if((active.first-areas[i].first) * c + active.second > areas[i].second)
          aright.push_back(active=areas[i]);
reverse(aright.begin(), aright.end());
for (int i = 0; i < m; i++)
{
   int t;
   ll best = inf;

   if(cin.bad()) err();

   cin >> t;

   if(t<0 || t > (int)1e9) err();
   if(cin.bad()) err();


   //намиране на най-близката ефективна площадка вляво, ако съществува
   vector<pii>  :: iterator l;
   l = upper_bound(aleft.begin(), aleft.end(), make_pair(t, inf1));
   if (l != aleft.begin())
      {
        l--;
        ll lans = (t - l->first) * c + l->second;
        if (lans < best)  best = lans;
      }
   vector<pii>  :: iterator r;
   r = upper_bound(aright.begin(), aright.end(), make_pair(t, 0));
   if (r != aright.end())
      {
        ll rans = (r->first - t) * c + r->second;
        if (rans < best)   best = rans;
      }
   cout << best << "\n";
}
}
