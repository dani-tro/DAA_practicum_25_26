#include <iostream>
#include <stack>
#include <math.h>
#include <iomanip>
using namespace std;

stack<long long> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long x;
    while(cin >> x)
    {
        s.push(x);
    }
	cout << fixed << setprecision(6);
    while(!s.empty())
    {
        cout  << sqrt(s.top()) << "\n";
        s.pop();
    }
}