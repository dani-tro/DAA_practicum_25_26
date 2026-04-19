#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cmath>
#include <time.h>
using namespace std;
const int maxn = 2e6+10, maxk = 1e6+10;

int a[maxn], n, max_value, kconst;
long long s;
bool used[maxn];
pair < long long, long long > b[maxn];

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

    int l = 1, r = cnt, steps = rand()%(n-1)+1;
    long long lasts;

    cout << "steps: " << steps << ' ' << n << ' ' << n-steps << '\n';

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

ofstream fout;

void build() {

    ifstream fin("constraints.txt");

    int min_n, max_n;

    fin >> min_n >> max_n;    

    n = rand()%(max_n - min_n + 1) + min_n;

    for (int i = 1 ; i <= n ; ++i) a[i] = i;
    calc_s();
    random_shuffle(a+1, a+1+n);

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