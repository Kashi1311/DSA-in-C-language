// examples on jumps in loop //
#include <iostream>
using namespace std;

int main(){
    int pocket_money = 3000;
    for(int date=1; date<=30; date++){
        if(date%2==0){
            continue;
        }
        if(pocket_money==0){
            break;
        }
        cout<<"you can go out today\n";
        pocket_money = pocket_money - 300;
    }
    
    return 0;
}
