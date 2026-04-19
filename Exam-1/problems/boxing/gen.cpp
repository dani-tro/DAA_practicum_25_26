#include <bits/stdc++.h>
using namespace std;

int main () {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	std::mt19937_64 gen(seed);
  	int test; cin >> test;
  	long long n;
  	
  	if (test <= 15) n = 1e4;
  	else if (test <= 25) n = 1e5;
  	else if (test <= 35) n = 2e6;
  	else n = 1e7;
  	
  	long long m = gen() % (long long)(2e9) + 1;
  	long long maxK = n * m / 10ll;
  	
  	cout << n << ' ' << gen() % maxK << endl;
  	cout << gen() % m + 1 << ' ' << gen() % m + 1 << ' ' << gen() % m + 1 << ' ' << gen() % m + 1 << ' ' << gen() % m + 1 << ' ' << m + 1 << endl;
}
