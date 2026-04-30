#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

long long n, a, b;

vector<int> gr[MAX];

long long col[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	for(int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	
	queue<int> q;
	q.push(1);
	col[1] = 1;
	long long col1 = 0, col2 = 0;
	
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		if(col[node] == 1)col1++;
		else col2++;
		
		for(auto u : gr[node])
		{
			if(col[u] == 0)
			{
				col[u] = (3 - col[node]);
				q.push(u);
			}
		}
	}
	
	cout << col1 * col2 - (n - 1) << endl;
	
	return 0;
}
