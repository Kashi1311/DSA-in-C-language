// Rat in a Maze problem //
#include<iostream>
using namespace std;

bool issafe(int** arr, int x, int y, int n){
    if(x < n && y < n && arr[x][y]==1){
        return true;
    }
    return false;
}
bool ratinMaze(int** arr, int x, int y, int n, int** solarr){

    if(x==n-1 && y==n-1){
        solarr[x][y]=1;
        return true;
    }

    if(issafe(arr, x, y, n)){
        solarr[x][y]=1;
        if(ratinMaze(arr, x+1, y, n, solarr)){     // Recursive call for x direction //
            return true;
        }
        if(ratinMaze(arr, x, y+1, n, solarr)){      // Recursive call for y direction //
            return true;
        }
        solarr[x][y]=0;       //Back Track //
        return false;
    }
    return false;
}
int main(){
    int n;
    cin>>n;

    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    int** solarr = new int*[n];
    for(int i=0;i<n;i++){
        solarr[i] = new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            solarr[i][j]=0;
        }
    }

    if(ratinMaze(arr, 0, 0, n, solarr)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<solarr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}

//    1 0 1 0 1
//    1 1 1 1 1
//    0 1 0 1 0
//    1 0 0 1 1
//    1 1 1 0 1 
