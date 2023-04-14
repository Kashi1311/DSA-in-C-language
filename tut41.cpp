// Maximum subarray sum in circular array //
#include<iostream>
#include<climits>
using namespace std;
int kadanes(int a[], int n){
    int currsum = 0;
    int maxsum = INT_MIN;
    for(int i=0;i<n;i++){
        currsum+=a[i];
        if(currsum<0){
            currsum = 0;
        }
        maxsum = max(maxsum , currsum);
    }
    return maxsum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int wrapsum;
    int nonwrapsum;
    nonwrapsum = kadanes(arr , n);
    int totalsum = 0;
    for(int i=0;i<n;i++){
        totalsum += arr[i];
        arr[i]=-arr[i];
    }
    wrapsum = totalsum + kadanes(arr , n);
    
    cout<<max(wrapsum , nonwrapsum)<<endl;

    return 0;
}