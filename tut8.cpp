// inverted hybrid pattern //
#include <iostream>
using namespace std;

int main(){
    int rows , columns;
    cin>>rows>>columns;
    for(int i=rows; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
