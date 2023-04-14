// Record Breaker Problem //
#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int array[n+1];
    array[n] = -1;
    
    for(int i=0;i<n;i++){
        cin>>array[i];;
    }

    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }

    int RBD = 0;
    int mx = -1;
    for(int i=0;i<n;i++){
        if(array[i] > mx && array[i] > array[i+1]){
            RBD++;
        }
        mx = max(mx , array[i]);
    }
    cout<<RBD<<endl;
    
    return 0;
}