// Graph Representation using adjaceny list //
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph {
    public:
    unordered_map<int, list<int> > adj;
    void addEdge(int x, int y, bool direction){
        adj[x].push_back(y);
        if(direction == 0){
            adj[y].push_back(x);
        }
    }
    void printadj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<< j  <<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the no. of nodes";
    cin>>n;
    int m;
    cout<<"Enter the no.of edges";
    cin>>m;
    //creating a graph. //
    graph g;
    for(int i=0;i<m;i++){
        int u, v;
        cin>> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printadj();
    return 0;
}