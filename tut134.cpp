// Set basic implementation. //
#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    for(auto i : s){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<s.size()<<"\n";
    s.erase(s.begin());
    s.erase(s.end());
    for(auto i : s){
        cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}

// for ordered set we use set<int> s  // for unordered set we use unordered_set<int> s and for multiset we use multiset<int> s //