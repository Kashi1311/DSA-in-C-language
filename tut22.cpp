// Fibonacci series using functions //
#include <iostream>
using namespace std;
void fibonacci(int n){
    int t1 = 0;
    int t2 = 1;
    int next_term;
    for(int i=1;i<=n;i++){
        cout<<t1<<endl;
        next_term = t1 + t2;
        t1 = t2;
        t2 = next_term;
    }
    return;
}

int main(){
    int n;
    cin>>n;
    fibonacci(n);
    return 0;

}