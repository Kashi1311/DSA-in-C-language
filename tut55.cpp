// A program to find 2 unique numbers in an array where all numbers except two , are present twice //

#include <iostream>
using namespace std;

int getbit(int n , int pos){
    return ((n & (1 <<pos))!=0);
}
void unique(int arr[] , int n){
    int xorsum = 0;
    for(int i=0;i<n;i++){
        xorsum = xorsum^arr[i];
    }
    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;

    while(setbit!=1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    
    int newxorsum = 0;
    for(int i=0;i<n;i++){
        if(getbit(arr[i],pos-1)){
            newxorsum = newxorsum^arr[i];
        }
    }

    cout<<newxorsum<<endl;
    cout<<(tempxor^newxorsum)<<endl;
}

int main(){
    int arr[] = {2,4,6,7,4,5,6,2};
    unique(arr , 8);
    return 0;
}