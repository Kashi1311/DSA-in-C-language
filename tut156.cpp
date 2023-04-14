// Fractional Knapsack using greedy algorithm. //
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)

bool compare(pii p1, pii p2){
    double v1 = (double) p1.ff/p1.ss;           // value per unit weight of first item . //
    double v2 = (double) p2.ff/p2.ss;           // value per unit weight of second item . //

    return v1 > v2;
}

int main(){
    int n;cin>>n;
    vii a(n);
    rep(i,0,n){
        cin>> a[i].ff >> a[i].ss;
    }
    int w;
    cin>>w;
    int ans = 0;
    sort(a.begin(), a.end(), compare);
    rep(i, 0, n){
        if(w > a[i].ss){             // if knapsack weight is greater than all the weights given , then add all the items. //
            ans += a[i].ff;
            w -= a[i].ss;
            continue;
        }
        double vw = (double) a[i].ff/a[i].ss;
        ans += vw * w;
        w = 0;
        break;
    }
    cout<< ans <<endl;
    return 0;
}