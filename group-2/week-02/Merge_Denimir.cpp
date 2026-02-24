#include<iostream>
using namespace std;
int arr1[1000006];
int arr2[1000006];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long m, n;
    cin>>m>>n;
    for(long long i=0; i<m; i++){
        cin>>arr1[i];
    }
    for(long long i=0; i<n; i++){
        cin>>arr2[i];
    }
    long long curr1 = 0, curr2 = 0;
    while(curr1<m && curr2<n){
        if(arr1[curr1]<arr2[curr2]){
            cout<<arr1[curr1]<<" ";
            curr1++;
        }
        else if(arr1[curr1]>arr2[curr2]){
            cout<<arr2[curr2]<<" ";
            curr2++;
        }
        else{
            cout<<arr1[curr1]<<" "<<arr2[curr2]<<" ";
            curr1++;
            curr2++;
        }
    }
    if(curr1==m){
        for(int i=curr2; i<n; i++){
            cout<<arr2[i]<<" ";
        }
    }
    else{
        for(int i=curr1; i<m; i++){
            cout<<arr1[i]<<" ";
        }
    }
    return 0;
}