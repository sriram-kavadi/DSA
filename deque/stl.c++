#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int>dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(5);
    dq.push_front(6);
    dq.push_front(7);
    dq.push_front(8);
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    return 0;
}