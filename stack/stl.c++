#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<s[2]<<endl;
    return 0;
}