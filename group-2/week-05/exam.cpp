# include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, F;
	cin >> N >> F;
	long long l = 1, r = 2e9, mid;

	while(l < r) 
	{
		mid = (l+r)/2;
		long long sum = mid*F + (mid*(mid-1))/2;
		// cout << l << " " << r << " :: " << mid << " " << sum << endl;
		if (sum >= N) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	// cout << l << " " << r << endl;
	cout << l << endl;
}