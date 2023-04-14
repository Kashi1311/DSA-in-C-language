//represent the first repeating element which has the smallest occurenece of index  //
#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m = 9;
    int idx[m];
    for(int i=0;i<m;i++){
        idx[i] = -1;
    }
    int minidx = 25;
    for(int i=0;i<n;i++){
        if(idx[a[i]]!=-1){
            minidx = min(minidx , idx[a[i]]);
        }
        else{
            idx[a[i]] = i ;
        }
    }
    if(minidx == 25){
        cout<<"-1"<<endl;
    }
    else{
        cout<<minidx+1 <<endl;
    }
    return 0;
}
