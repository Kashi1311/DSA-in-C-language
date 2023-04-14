// remove all duplicates in a given string //
#include <iostream>
#include <string.h>
using namespace std;

string removedduplicates(string s){
    if(s.length()==0){
        return"";
    }
    char ch = s[0];
    string ans = removedduplicates(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return ch+ans;
}
int main(){
    cout<<removedduplicates("aaaabbbeeecdddd");
    return 0;
}