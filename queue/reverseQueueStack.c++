#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse(queue<int>&q){
    stack<int>st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

}

int main(){
    queue<int>q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }

    reverse(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}