// Sliding Window Challenge 2. // 
// Smallest subarray with sum > X . //
#include<iostream>
#include<climits>
using namespace std;

int smallestSubarraysum(int arr[], int n, int X){
    int sum = 0, minlength = n+1, start = 0, end = 0;
    while(end < n){
        while(sum <= X && end < n){
            sum += arr[end++];
        }

        while(sum > X && start < n){
            if(end - start < minlength){
                minlength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minlength;
}

int main(){
    int arr[] = {1,4,45,6,10,19};
    int X = 51;
    int n = 6;
    int minLenght = smallestSubarraysum(arr, n, X); 
    if(minLenght == n+1){
        cout<<"No such subarray exists"<<endl;
    }
    else{
        cout<<" smallest subarray sum with minlength is : "<<minLenght<<endl;
    }

    return 0;
}