#include <iostream>

using namespace std;

long long n, a, sum = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> n;
	//scanf("%lld", &n);
	
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		//scanf("%lld", &a);
		sum += a;
	}
	
	cout << sum << endl;
	//printf("%lld\n", sum);
	return 0;
}
