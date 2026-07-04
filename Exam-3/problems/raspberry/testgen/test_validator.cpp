#include "testlib.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#define MAXN 500
#define MAXM 500
#define MAXV 1000
#define MINV -1000
using namespace std;
void error_message (const char message[]) {
    cerr << "Error - " << message << "\n";
    exit(0);
}
set <string> def;
map <string, int> cnt;
int main (int argc, char* argv[]) {
    if (argc==1) error_message("the test validator needs arguments!\n");
    FILE* fin;
    fin=fopen(argv[1],"r");
    if (fin==NULL) error_message("wrong test name!");
    fclose(fin);
    freopen(argv[1],"r",stdin);
    registerValidation(argc,argv);

    int n=inf.readInt(1,MAXN,"N"); inf.readSpace();
    int m=inf.readInt(1,MAXM,"M"); inf.readEoln();
    bool pos=true;
    int num;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            num=inf.readInt(MINV,MAXV,"aij");
            if (j!=m-1) inf.readSpace();
            if (num<0) pos=false;
        }
        inf.readEoln();
    }
    inf.readEof();

    cout << n << " " << m << " " << pos << endl ;
    if ((n==1)&&(m<=MAXM)&&((num>0)||(n+m==2))) cout << "Second subtask!\n";
    else if ((n<=5)&&(m<=5)&&((num>0)||(n+m==2))) cout << "Third subtask!\n";
    else if ((n<=100)&&(m<=100)&&((num>0)||(n+m==2))) cout << "Fourth subtask!\n";
    else if ((n<=MAXN)&&(m<=MAXM)&&(pos==true)) cout << "Fifth subtask!\n";
    else if ((n<=MAXN)&&(m<=MAXM)&&((num>0)||(n+m==2))) cout << "Sixth subtask!\n";
    else if ((n<=MAXN)&&(m<=MAXM)) cout << "Seventh subtask!\n";
    else cout << "? subtask!\n";
    cout << "Test is OK!\n";
    return 0;
}
