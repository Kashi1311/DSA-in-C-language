// Breadth - first search . //
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void prepare_adj(unordered_map<int, list<int> > &adj, vector<pair<int, int> > &edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void printadj(unordered_map<int, list<int> > &adj){
    for(auto i: adj){
        cout<< i.first << "->";
        for(auto j: i.second){
            cout<< j << ",";
        }
        cout<<endl;
    }
}

void bfs(unordered_map<int, list<int> > &adj, vector<int> &ans, unordered_map<int, bool> &visited, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;    // node visited //
    
    while(!q.empty()){
        int front_node = q.front();
        q.pop();
        //store the value in ans //
        ans.push_back(front_node);
        // traverse all the neighbors of that node //
        for(auto i: adj[front_node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;

            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int> > edges){
    unordered_map<int, list<int> > adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepare_adj(adj, edges);
    printadj(adj);

    // traverse all components of a graph. //
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj, ans, visited, i);
        }
    }
    return ans;
}
int main(){
    vector<int> BFS(int vertex, vector<pair<int, int> > edges);
    return 0;
}
