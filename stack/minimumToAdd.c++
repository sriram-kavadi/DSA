#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int minToAdd(string parentheses){
    stack<char>st;
    for(char ch:parentheses){
        if(ch=='('){
            st.push(ch);
        }else{
            if( !st.empty() && st.top()=='('&&ch==')'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
    }

    return st.size();
}

int main(){
    string str="())))()(((())))";
    cout<<minToAdd(str);
    return 0;
}