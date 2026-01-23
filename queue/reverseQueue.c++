#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }
    queue<int>temp1;
    queue<int>temp2;
    while(!q.empty()){
        while(!temp1.empty()){
            temp2.push(temp1.front());
            temp1.pop();
        }
        temp1.push(q.front());
        while(!temp2.empty()){
            temp1.push(temp2.front());
            temp2.pop();
        }
        q.pop();
    }

    while(!temp1.empty()){
        cout<<temp1.front()<<" ";
        temp1.pop();
    }
    cout<<endl;
    return 0;
}