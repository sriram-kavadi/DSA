#include<iostream>
#include<queue>
using namespace std;

void interLeave(queue<int>q){
    queue<int>firstHalf;
    queue<int>answer;
    int n=q.size();
    int i=0;
    while(!q.empty()&&i<n/2){
        firstHalf.push(q.front());
        q.pop();
        i++;
    }

    while(!q.empty()&&!firstHalf.empty()){
        q.push(firstHalf.front());
        q.push(q.front());
        q.pop();
        firstHalf.pop();
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    interLeave(q);
    return 0;
}