#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;

int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
	int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i < n; i++) {
        int minn = a[i], minIndex = i;
        
        for(int j = i; j <= n; j++) {
            if(a[j] < minn) {
                minn = a[j];
                minIndex = j;
            }
        }
        
        swap(a[i], a[minIndex]);
        for(int j = 0; j < n; j++) cout << a[j] << ' ';
        cout << endl;
    }
    return 0;
}
