/* test generator uses testlib.h: https://github.com/MikeMirzayanov/testlib/blob/master/testlib.h
   arguments:
    - first - name of the test that will be generated
    - second - value of n
    - third - value of m
    - fourth - flag all nonnegative
    - fifth - flag last cell
    - sixth - type of test
        = 0 - random table
        = 1 - small number of negatives
        = 2 - large number of negatives
    - seventh, ... - used for seed for registerGen */
#include "testlib.h"
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
#include "test_generator.h"
#define MAXN 1000
#define MAXM 1000
#define MAXV 1000
using namespace std;

int a[MAXN][MAXM];
int main (int argc, char** argv) {
    if (argc==1) {
       cout << "The test generator needs arguments!\n";
       return 0;
    }
    check_tests(argc,argv);
    if (argc<6) {
       cout << "The test generator needs more arguments!\n";
       return 0;
    }
    registerGen(argc,argv,1);
    ofstream fout(argv[1]);
    int n,m;
    n=atoll(argv[2]); m=atoll(argv[3]);
    bool pos,last;
    pos=atoll(argv[4]); last=atoll(argv[5]);
    int type;
    type=atoll(argv[6]);

    if (type==0) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (pos==false) a[i][j]=rnd.next(-MAXV,MAXV);
                else a[i][j]=rnd.next(0,MAXV);
            }
        }
        if (pos==false) {
            int x=rnd.next(0,n/2),y=rnd.next(0,m/2);
            for (int i=x; i<x+n/2; i++) {
                for (int j=y; j<y+m/2; j++) {
                    a[i][j]=rnd.next(-MAXV,-1);
                }
            }
        }
    }
    else {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (type==1) {
                    if (rnd.next(m+(min(n,m)-min(i,j)))==0) a[i][j]=rnd.next(-MAXV,-1);
                    else a[i][j]=rnd.next(0,MAXV);
                }
                else {
                    if (rnd.next(5+(min(n,m)-min(i,j)))==0) a[i][j]=rnd.next(-MAXV,-1);
                    else a[i][j]=rnd.next(0,MAXV);
                }
            }
        }
    }
    if (last==true) a[n-1][m-1]=rnd.next(1,MAXV);
    else if (pos==false) {
        vector <int> xs;
        for (int i=2*n/3; i<n; i++) {
            xs.push_back(i);
        }
        shuffle(xs.begin(),xs.end());
        int cnt=rnd.next(1,max(1,min({10,n/3,m/3})));
        sort(xs.begin(),xs.begin()+cnt);
        reverse(xs.begin(),xs.begin()+cnt);
        vector <int> ys;
        for (int i=2*m/3; i<m; i++) {
            ys.push_back(i);
        }
        shuffle(ys.begin(),ys.end());
        sort(ys.begin(),ys.begin()+cnt);
        for (int i=0; i<cnt; i++) {
            cout << "(" << xs[i] << "," << ys[i] << ") ";
            for (int j=xs[i]; j<n; j++) {
                for (int h=ys[i]; h<m; h++) {
                    a[j][h]=rnd.next(-MAXV,-1);
                }
            }
        }
    }

    fout << n << " " << m << endl ;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            fout << a[i][j] ;
            if (j!=m-1) fout << " ";
        }
        fout << endl ;
    }
    fout.close();

    cout << "test successfully generated!!!" << endl ;
    validate_test(argc,argv);
    return 0;
}
