// sum of all subarrays //
#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<endl;
    int current = 0;
    for(int i=0;i<n;i++){
        current = 0;
        for(int j=0;j<n;j++){
            current += array[j];
            cout<<current<<",";
        }cout<<endl;
        
    }
   
    return 0;
}