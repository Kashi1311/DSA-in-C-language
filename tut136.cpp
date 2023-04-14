// Page allocation problem. //
#include<iostream>
#include<climits>
using namespace std;

bool isFeasible(int min, int arr[], int n, int m){
    int studentsRequired = 1, sum = 0;

    for(int i=0;i<n;i++){
        if(arr[i] > min){
            return false;
        }
        if(sum+arr[i] > min){
            studentsRequired++;
            sum = arr[i];

            if(studentsRequired > m){
                return false;
            }
        }
        else{
            sum += arr[i];
        }
    }

    return true;
}

int allocatemin(int arr[], int n, int m){
    int sum = 0;
    if(n < m){
        return -1;
    }

    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    int start = 0;
    int end = sum;
    int ans = INT_MAX;

    while(start < end){
        int mid= (start + end)/2;
        if(isFeasible(mid, arr, n, m)){
            ans = min(ans, mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {12,34,67,90};
    int n = 4;
    int m = 2;
    cout<<allocatemin(arr, n, m);
    return 0;
}