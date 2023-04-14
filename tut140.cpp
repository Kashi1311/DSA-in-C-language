// Sliding Window Challenge 1. // 
// Maximum sum subarray of size = k & sum < X . //
#include<iostream>
using namespace std;

void maxSubarraysum(int arr[], int n, int k, int X){
    int sum = 0, ans = 0;\

    for(int i=0;i<k;i++){
        sum += arr[i];   // calculated sum of forst k elements;
    }
    
    if(sum < X){
        ans = sum;
    }

    for(int i=k;i<n;i++){
        sum = sum - arr[i-k];
        sum = sum + arr[i];
        if(sum < X){
            ans = max(ans, sum);
        }
    }

    cout<<ans<<" is the maximum subarray sum."<<endl;
}

int main(){
    int arr[] = {7,5,4,6,8,9};
    int k = 3;
    int X = 20;
    int n = 6;
    maxSubarraysum(arr, n, k, X); 

    return 0;
}