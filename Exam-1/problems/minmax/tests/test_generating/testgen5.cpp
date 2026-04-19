#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <cmath>
#include <time.h>
using namespace std;
const int maxn = 2e6+10, maxk = 1e6+10;

int a[maxn], n, maxnum;
long long s;
pair < int, int > b[maxn];

void build_array() {

    int l = 1, r = n, ix = 1;

    while (ix <= n) {

        int add = rand()%(int)sqrt(n-ix+1)+1;

        if (rand()%2) {

            for (int i = 1 ; i <= add && ix <= n ; ++i, ++ix) a[ix] = l;
            ++l;

        } else {
            
            for (int i = 1 ; i <= add && ix <= n ; ++i, ++ix) a[ix] = r;
            --r;

        }

    }

    sort(a+1, a+1+n);

}

void calc_s() {

    int cnt = 1;
    b[1] = {a[1], 1};

    for (int i = 2 ; i <= n ; ++i) {

        if (a[i] == a[i-1]) ++b[cnt].second;
        else b[++cnt] = {a[i], 1};

    }

    if (cnt == 1) {

        s = rand()%(long long)1e14+1;
        return;

    }

    int l = 1, r = cnt, steps = rand()%(cnt-1)+1;
    long long lasts;

    while (steps >= 1 && l < r) {

        if (b[l].second <= b[r].second) {

            lasts = s;
            s += (b[l+1].first - b[l].first) * b[l].second;
            b[l+1].second += b[l].second;
            ++l;

        } else {

            lasts = s;
            s += (b[r].first - b[r-1].first) * b[r].second;
            b[r-1].second += b[r].second;
            --r;

        }
        
        --steps;

    }

    s = rand()%(s-lasts) + lasts;

}

set < int > numbers;
unordered_map < int, int > m;

void decompress() {

    for (int i = 1 ; i <= n ; ++i) {

        int curr;
        do curr = rand()%(int)maxnum+1;
        while (numbers.count(curr));
        numbers.insert(curr);

    }

    auto it = numbers.begin();
    for (int i = 1 ; i <= n ; ++i, ++it)
        m[i] = (*it);

    for (int i = 1 ; i <= n ; ++i)
        a[i] = m[a[i]];

}

unordered_map < int, int > mp;

ofstream fout;

bool solve() {

    long long minval = 1e9+1, maxval = 0;
    long long mincnt, maxcnt;
    
    for (int i = 1 ; i <= n && s > 0; ++i) {

        minval = 1e9+1;
        maxval = 0;
        mincnt = maxcnt = 0;

        for (int j = 1 ; j <= n ; ++j) {

            if (a[j] == minval) ++mincnt;
            if (a[j] < minval) minval = a[j], mincnt = 1;
            if (a[j] == maxval) ++maxcnt;
            if (a[j] > maxval) maxval = a[j], maxcnt = 1;

        }

        if (minval == maxval || s < min(mincnt, maxcnt)) return 1;

        if (mincnt <= maxcnt) {

            for (int i = 1 ; i <= n ; ++i)
                if (a[i] == minval) ++a[i];

            s -= mincnt;

        } else {

            for (int i = 1 ; i <= n ; ++i)
                if (a[i] == maxval) --a[i];

            s -= maxcnt;
            
        }

    }

    if (s == 0) return 1;
    return 0;

}

void build() {

    ifstream fin("constraints.txt");

    int min_n, max_n;
    fin >> min_n >> max_n;
    fin >> maxnum;
    
    do {

        n = rand()%(max_n - min_n + 1) + min_n;
        // cout << "divide " << n << ' ' << k << "\n";
    
        build_array();
        decompress();
        calc_s();
        random_shuffle(a+1, a+1+n);

    } while (solve());

    // cout << "decompress\n";

    fout << n << ' ' << s << '\n';
    for (int i = 1 ; i <= n ; ++i) {

        if (i >= 2) fout << ' ';
        fout << a[i];

    }

    fout << '\n';

}

int main (int argc, char** argv) {

    srand(time(nullptr));

    if (argc != 2) {

        cout << "There should be exactly one argument - the name of the in file!\n";
        return 0;

    }

    fout.open(argv[1]);
    build();
    
    return 0;

}