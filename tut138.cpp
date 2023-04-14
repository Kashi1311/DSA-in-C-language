// Search element in sorted and rotated array. //
#include<iostream>
using namespace std;

int searchinRotatedarray(int arr[], int key, int left, int right){
    if(left > right){
        return -1;
    }
    int mid  =(left + right)/2;
    if(arr[mid] == key){
        return mid;
    }
    if(arr[left] <= arr[mid]){
        if(key <= arr[mid] && key >= arr[left]){
            return searchinRotatedarray(arr, key, left, mid-1);
        }
        else{
            return searchinRotatedarray(arr, key, mid+1, right);
        }
    }
    if(key >= arr[mid] && key <= arr[right]){
        return searchinRotatedarray(arr, key, mid+1, right);
    }
    return searchinRotatedarray(arr, key, left, mid-1);
}

int main(){
    int arr[] = {6,7,8,9,10,1,2,5};
    int n = 8;
    int key = 8;
    cout<<searchinRotatedarray(arr, key, 0, n-1);

    return 0;
}
