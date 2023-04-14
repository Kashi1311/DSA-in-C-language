// Median of running stream. //
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;


priority_queue <int, vector<int> > pqmax;
priority_queue <int, vector<int>, greater<int> > pqmin;

void insert(int x){
    // case 1 both sizes are equal. //
    if(pqmin.size() == pqmax.size()){
        if(pqmax.size() == 0){
            pqmax.push(x);
            return;
        }
        if(x < pqmax.top()){
        pqmax.push(x);
        }
        else{
        pqmin.push(x);
        }
    }
    //case 2 both sizes are not equal . //
    else{
        if(pqmax.size() > pqmin.size()){
            if(x >= pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        if(pqmax.size() < pqmin.size()){
            if(x <= pqmin.top()){
                pqmin.push(x);
            }
            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian(){
    if(pqmax.size() == pqmin.size()){
        return (pqmax.top() + pqmin.top())/2.0;
    }
    else if(pqmax.size() > pqmin.size()){
        return pqmax.top();
    }
    else{
        return pqmin.top();
    }
}

int main(){

    insert(10);
    insert(15);
    insert(21);
    insert(30);
    insert(18);
    insert(19);
    cout<<findMedian()<<endl;
    return 0;

}