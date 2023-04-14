// smallest positive mising number //
#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    const int m = 20;
    bool check[m];
    for(int i=0;i<m;i++){
        check[i] = false;
    }
    for(int i=0;i<n;i++){
        if(a[i]>0){
            check[a[i]]= true;
        }
    }
    int ans = 0;
    for(int i=1;i<m;i++){
        if(check[i] == false){
            ans = i;
            break;
        }
    }
    cout<< ans << endl;
    
    return 0;
}
