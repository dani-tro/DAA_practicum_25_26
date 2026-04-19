# include <bits/stdc++.h>
using namespace std;
long long A, K, B, M, X;
long long calc(long long days)
{
	long long ans = A*(days - (days/K));
	ans += B*(days - (days/M));
	return ans;
}
int main()
{
	cin >> A >> K >> B >> M >> X;
	long long l = 1, r = 2*X/(A+B), mid;
	while (l < r) {
		mid = (l+r)/2;
		if (calc(mid) >= X) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << endl;
}