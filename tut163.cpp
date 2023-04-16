#include<iostream>
#include<vector>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define setBits(x) builtin_popcount(X)

const int N = 1e5+2, MOD = 1e9+7;

int main(){
    int n,m;
    cin>>n>>m;
    vvi adjm(n+1, vi(n+1,0));

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;

    }
    cout<<"adjacency matrix of above graph is given by: "<<endl;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<adjm[i][j]<<" ";
        }
        cout<<endl;
    }

    if(adjm[3][7] == 1){
        cout<<"there is an edge between 3 and 7 "<<endl;
    }
    else{
        cout<<"no edge"<<endl;
    }
    cout<<endl;
    return 0;
}