#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <time.h>
using namespace std;
const int maxn = 2e6+10, maxk = 1e6+10;

int a[maxn], n, maxnum, kconst;
bool used[maxn];

ofstream fout;

void build() {

    ifstream fin("constraints.txt");

    int min_n, max_n;
    fin >> min_n >> max_n;   
    fin >> maxnum;

    n = rand()%(max_n - min_n + 1) + min_n;

    int rnd = rand()%(int)maxnum+1;


    for (int i = 1 ; i <= n ; ++i) a[i] = rnd;

    fout << n << ' ' << rand()%(long long)1e14+1 << '\n';
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