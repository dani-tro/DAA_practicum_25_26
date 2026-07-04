#include<iostream>
#include<string.h>
#include<fstream>
#include<string>
using namespace std;
int get_test_number (const string& s) {
    int ind=0;
    for (;;) {
        if ((ind==s.size())||(s[ind]!='.')) break;
        ind++;
    }
    bool fl=false;
    int num=0;
    for (int i=ind; i<s.size(); i++) {
        if (s[i]=='.') {
            if (fl==true) return num;
            fl=true;
        }
        else if ((s[i]>='0')&&(s[i]<='9')&&(fl==true)) num*=10, num+=s[i]-'0';
    }
    return -1;
}
string get_test_name (const string& s) {
    string temp;
    for (int i=0; i<s.size(); i++) {
        if (s[i]==' ') break;
        temp+=s[i];
    }
    return temp;
}
string convert_params_to_string (int argc, char** argv) {
    string s;
    s="";
    for (int i=0; i<argc; i++) {
        s+=string(argv[i]);
        s+=" ";
    }
    return s;
}
string change_test_number (const string& s, int number) {
    int n=s.size(),ind=n-1,cnt=0;
    for (;;) {
        if (ind==-1) break;
        if (s[ind]=='.') cnt++;
        if (cnt==2) break;
        ind--;
    }
    string temp=s.substr(0,ind+1);
    if (number<10) temp+="0";
    temp+=to_string(number);
    bool fl=true;
    for (int i=ind+1; i<s.size(); i++) {
        if (s[i]=='.') fl=false;
        if (fl==false) temp+=char(s[i]);
    }
    return temp;
}
string change_extension (const string& s, const string& ext) {
    int cnt=0,cnt2=0;
    string temp;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='.') cnt++;
    }
    for (int i=0; i<s.size(); i++) {
        temp+=s[i];
        if (s[i]=='.') cnt2++;
        if (cnt2==cnt) {
            temp+=ext;
            break;
        }
    }
    return temp;
}
void check_tests (int& argc, char**& argv) {
    fstream tests("tests_properties.txt",ios::in|ios::out);
    if (tests.is_open()==0) tests.open("tests_properties.txt",ios::in|ios::out|ios::trunc);
    string s,output[2][100],test_name(argv[1]);
    int lens[2]={-1,0},num,test_number,fl=0;
    char choice;

    if ((test_name[0]>='0')&&(test_name[0]<='9')) {
        cout << "Are you sure you have given test name as parameter?\n";
        cin >> choice ;
        if ((choice=='n')||(choice=='N')) {
            cout << "Test name: ";
            cin >> test_name ;
            argc++;
            char** temp = new char*[argc];
            for (int i=argc-1; i>=2; i--) {
                temp[i]=argv[i-1];
            }
            temp[1] = new char [test_name.size()+1];
            strcpy(temp[1],test_name.c_str());
            temp[0]=argv[0];
            argv=temp;
        }
    }

    test_number=get_test_number(test_name);
    while (getline(tests,s,'\n')) {
        int st,fin,cnt=0;
        for (int i=0; i<s.size(); i++) {
            if ((s[i]==' ')||(s[i]=='\t')) {
                cnt++;
                if (cnt==2) {
                    fin=i-1;
                    break;
                }
                st=i+1;
            }
        }
        if ((cnt<2)||(st==fin)) continue;
        string curr_name=s.substr(st,fin-st+1);
        num=get_test_number(curr_name);
        if ((curr_name==test_name)||((test_number!=-1)&&(test_number==num))) {
            cout << "Are you sure you want to overwrite\n" << s << " with\n" << convert_params_to_string(argc,argv) << "?\n";
            cin >> choice ;
            if ((choice=='y')||(choice=='Y')) {
                s=convert_params_to_string(argc,argv);
                fl=1;
            }
            else if (test_number!=-1) {
                cout << "Do you want just to insert " << s << "?\n";
                cin >> choice ;
                if ((choice=='y')||(choice=='Y')) fl=2;
                else exit(0);
            }
            else exit(0);
        }
        if (num!=-1) output[0][num]=s, lens[0]=max(lens[0],num);
        else output[1][lens[1]++]=s;
        num++;
    }
    tests.close(); tests.open("tests_properties.txt",ios::out|ios::trunc);
    if (fl==2) {
        for (int i=lens[0]; i>=test_number; i--) {
            s=change_test_number(output[0][i],i+1);
            rename(get_test_name(output[0][i]).c_str(),get_test_name(s).c_str());
            rename(change_extension(get_test_name(output[0][i]),"sol").c_str(),
                   change_extension(get_test_name(s),"sol").c_str());
            output[0][i+1]=s;
        }
        output[0][test_number]=convert_params_to_string(argc,argv); lens[0]++;
    }
    else if (fl==0) {
        if (test_number!=-1) {
            output[0][test_number]=convert_params_to_string(argc,argv);
            lens[0]=max(lens[0],test_number);
        }
        else output[1][lens[1]++]=convert_params_to_string(argc,argv);
    }
    tests.seekp(0,ios::beg);
    for (int i=0; i<=lens[0]; i++) {
        tests << output[0][i] << "\n";
    }
    tests << "\n";
    for (int i=0; i<lens[1]; i++) {
        tests << output[1][i] << "\n";
    }
    cout << "Starting to generate test " << test_name << "!" << endl ;
}

void validate_test (int argc, char** argv) {
    string command="test_validator "+string(argv[1]);
    system(command.c_str());
}
