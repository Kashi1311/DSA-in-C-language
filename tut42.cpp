// Pair Sum Problem //
#include<iostream>
using namespace std;
bool pairsum(int a[] , int n , int k){
    int low = 0;
    int high = n-1;
    while(low<high){
        if(a[low]+a[high]==k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(a[low]+a[high]==k){
            cout<<low<<" "<<high;
            return true;
        }
        else if(a[low]+a[high]>k){
            high--;
        }
        else{
            low++;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    
    cout<<pairsum(arr, n ,key);
    return 0;
}