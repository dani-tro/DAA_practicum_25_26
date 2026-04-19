#include <bits/stdc++.h>
using namespace std;

long long a[100000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    long long s; cin >> s;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    int left = 0;
    int right = n-1;

    while (true) {
        while (left < n && a[left] == a[left+1]) left++;
        while (right >= 0 && a[right] == a[right-1]) right--;
        if (left >= right) break;

        if (left+1 < n-right) {
            int br = left+1;
            long long diff = a[left+1]-a[left];
            if (s < br) break;
            a[left] += min(s/br, diff);
            s -= br*min(s/br, diff);
        } else {
            int br = n-right;
            long long diff = a[right]-a[right-1];
            if (s < br) break;
            a[right] -= min(s/br, diff);
            s -= br*min(s/br, diff);
        }
    }

    if (left >= right) cout << 0 << endl;
    else cout << a[right]-a[left] << endl;

    return 0;
}
