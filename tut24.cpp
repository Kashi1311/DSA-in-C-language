// Linear search in a given array //
#include <iostream>
using namespace std;

int linearsearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    
    return-1;
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

    cout<<linearsearch(array, n, key);

    return 0;
}