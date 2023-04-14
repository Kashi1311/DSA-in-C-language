// greedy - optimal pattermn merge. //
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i, a, b) for(int i=a;i<b;i++)

int main(){
    int n;cin>>n;
    vector<int> a(n);
    rep(i, 0, n){
        cin>>a[i];
    }
    priority_queue<int, vector<int>, greater<int> > minHeap;
    rep(i, 0, n){
        minHeap.push(a[i]);
    }
    int ans = 0;
    while(minHeap.size() > 1){
        int e1 = minHeap.top();
        minHeap.pop();
        int e2 = minHeap.top();
        minHeap.pop();
        ans += e1 + e2;
        minHeap.push(e1 + e2);
    }
    cout<< ans << endl;
    return 0;
}