// reverse of an array //
#include <iostream>
using namespace std;

void reversearray(int arr[], int start, int end){
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
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
    reversearray(array, 0, n-1);
    cout<<"Reverse array is : ";
    for(int i=0;i<n;i++){
        cout<<array[i]<<",";
    }  
    return 0;
}