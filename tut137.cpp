// Painrters Partition Problem. //
#include<iostream>
#include<climits>
using namespace std;

int findFeasible(int arr[], int limit, int n){
    int sum = 0, painter = 1;

    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum > limit){
            sum = arr[i];
            painter++;
        }
    }
    return painter;
}

int paintersPartition(int arr[], int n, int m){
    int total_length  = 0, k = 0;
    for(int i=0;i<n;i++){
        k = max(k, arr[i]);
        total_length += arr[i];
    }

    int low = k, high = total_length;
    while(low < high){
        int mid = (low + high)/2;
        int painters = findFeasible(arr, mid, n);
        if(painters <= m){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }

    return low;
}

int main(){

    int arr[] = {10,20,30,40};
    int n = 4;
    int m = 2;
    cout<<"Minimum time to paint boards is : "<<paintersPartition(arr, n ,m)<<endl;
    return 0;
}