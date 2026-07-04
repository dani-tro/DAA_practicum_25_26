/* the core program has three arguments:
   - first - state of checking with three possible values:
              = 0 - checks the solution file according the answer file
              = x>0 - generates solution file with name from the third argument using the x-th solution
   - second - name of the input file
   - third - name of the file to be checked or generated
   - fourth - name of the correct output file (optional - only for option 0) */
#include<iostream>
#include<string>
#include<vector>
#include "checker_tgen.h"
using namespace std;


int main (int argc, char** argv) {
    ifstream inp,out,ans;
    vector <string> solutions={
        "raspberry_cheat",
        "raspberry_subtask2_7p",
        "raspberry_subtask3_11p",
        "raspberry_subtask4_32p",
        "raspberry_subtask5_19p",
        "raspberry_subtask6_79p",
        "raspberry_subtask7_100p"
    };
    check_arguments(argc,argv,inp,out,ans,solutions,"");
    inp.close();
    long long int ans_out,ans_sol;
    out >> ans_out ;
    out.close();
    ans >> ans_sol ;
    ans.close();
    if (ans_out==ans_sol) cout << "OK!";
    else cout << "WA!\n" << ans_out << endl << ans_sol ;
    /*string command="..\\checker\\checker "+string(argv[2])+" "+string(argv[4])+" "+string(argv[3]);
    system(command.c_str());*/
    cout << endl ;
    return 0;
}
