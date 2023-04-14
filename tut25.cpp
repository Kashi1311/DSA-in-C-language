// Binary search for a given array //
#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int key){
    int low = 0;
    int high = n;
    while(low<=high){
        int mid = (low + high)/2;

        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }

    return -1;
}


int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<",";
    }

    cout<<endl;

    int key;
    cin>>key;

    cout<<binarysearch(array ,n ,key);

    return 0;
}