// chocolate distribution problem //
#include <iostream>
using namespace std;

int findminimumdifference(int a[], int n, int m){
    
    if(n==0 || m==0){
        return 0;
    }

    if(n<m){
        return -1;
    }
    
    int min_diff = 100;
    for(int i=0;i+m-1<n;i++){
        int diff = a[i+m-1] - a[i];
        if(diff<min_diff){
            min_diff = diff;
        }
    }
    return min_diff;
}
int main(){

    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<",";
    }
    cout<<endl;
    int m;
    cin>>m;
    cout<<"Minimum Difference is : "<<findminimumdifference(array , n , m);
    return 0;

}