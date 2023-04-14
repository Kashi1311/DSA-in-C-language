// a program to generate all posible subsets of a given set //
#include <iostream>
using namespace std;

void subsets(char arr[] , int n){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }cout<<endl;
    }
}
int main(){
    char array[3] = {'a' , 'b' , 'c'};
    subsets(array,3);
    return 0;
}