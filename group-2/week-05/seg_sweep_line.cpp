#include <bits/stdc++.h>

using namespace std;

int n, a, b, sum, ansl, anscnt, currb;

struct event
{
	int idx;
	int flag;
	
	bool operator<(const event& other)
	{
		if(idx != other.idx)return idx < other.idx;
		return flag > other.flag;
	}
};

vector<event> events;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if(a > b)swap(a, b);
		events.push_back({a, +1});
		events.push_back({b, -1});
	}
	
	sort(events.begin(), events.end());
	
	for(auto e : events)
	{
		sum += e.flag;	
		if(sum == 1 && e.flag == 1)
		{
			currb = e.idx;
		}
		if(sum == 0)
		{
			ansl = max(ansl, e.idx - currb);
			anscnt++;
		}

	}
	
	cout << anscnt << " " << ansl << endl;
	
	return 0;
}
