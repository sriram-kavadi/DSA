#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int minCost(priority_queue<int,vector<int>,greater<int>>&pq){
    int temp=0;
    while(!pq.empty()){
        int value1=pq.top();
        pq.pop();
        if(pq.empty()){
            break;
        }
        int value2=pq.top();
        pq.pop();
        temp+=(value1+value2);
        pq.push(temp);
    }

    return temp;
    
}

int main(){
    priority_queue<int,vector<int>,greater<int>>pq;

    pq.push(4);
    pq.push(3);
    pq.push(2);
    pq.push(6);

    cout<<minCost(pq)<<endl;

    return 0;

}