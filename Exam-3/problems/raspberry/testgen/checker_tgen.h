#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include<time.h>
using namespace std;
void output_message (double points, string message) {
    cout << points << endl ;
    cerr << message << endl ;
    exit(0);
}
char* change_extension (string s, string ext) {
    int ind=0;
    for (int i=s.size()-1; i>=0; i--) {
        if (s[i]=='.') {
            ind=i;
            break;
        }
    }
    string name=s.substr(0,ind+1)+ext;
    char* temp=new char[name.size()+1];
    strcpy(temp,name.c_str());
    return temp;
}
void check_arguments (int& argc, char**& argv, ifstream& inp, ifstream& out, ifstream& ans, vector <string>& solutions, string command) {
    double beg_time,end_time;
    int state,fd[4];
    if (argc<2) output_message(0,"The program needs arguments!");
    state=atoi(argv[1]);
    if (state==0) {
       if (argc<4) output_message(0,"For the first option the checker needs input file, output file and correct output file (optional)!");
       else if (argc==4) argc++, argv[4]=change_extension(argv[2],"sol");
    }
    else {
        if (argc<3) output_message(0,"For this option the checker needs input file and correct output file (optional)!");
        else if (argc==3) {
            argc++; argv[3]=change_extension(argv[2],"sol");
            argc++; argv[4]=argv[3];
        }
        else if (argc==4) {
            argc++; argv[4]=change_extension(argv[2],"sol");
        }
    }

    inp.open(argv[2]);
    if (inp.is_open()==false) output_message(0,"Could not open input file!");

    if (state>0) {
        command+="..\\solutions\\";
        string solution;
        state--;
        if ((state>0)&&(state<solutions.size())) solution=solutions[solutions.size()-1-state];
        else solution=solutions[solutions.size()-1];
        command+=solution+" times.txt <"+string(argv[2])+" >"+string(argv[3]);
        beg_time=clock();
        system(command.c_str());
        end_time=clock();
        cout << solution << " working time: ";
        cout << fixed << setprecision(2) << (end_time-beg_time)/CLOCKS_PER_SEC << " s" << endl ;
    }

    out.open(argv[3]);
    if (!out) output_message(0,"Could not open output file!");
    ans.open(argv[4]);
    if (!ans) output_message(0,"Could not open answer file!");
}
