// contains duplicate problem //
#include <iostream>
using namespace std;
int containsduplicate(int nums[] , int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i] == nums[j]){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    if(containsduplicate(array , n)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
    return 0;
}