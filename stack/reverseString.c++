#include<iostream>
#include<string>
#include<stack>
using namespace std;

void reverse(string &s){
    stack<char>temp;
    for(auto i:s){
        temp.push(i);
    }
    s.clear();
    while(!temp.empty()){
        s.push_back(temp.top());
        temp.pop();
    }
}

int main(){
    string s="hello";
    cout<<s<<endl;
    reverse(s);
    cout<<s<<endl;
    return 0;
}