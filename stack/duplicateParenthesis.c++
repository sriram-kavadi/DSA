#include<iostream>
#include<stack>
using namespace std;

bool isDuplicate(string s){
    stack<char>st;

    for(char ch:s){
        if(ch!=')'){
            st.push(ch);
        }else{
            if(st.top()=='('){
                return true;
            }
            while(st.top()!='('){
                st.pop();
            }
            st.pop();
        }
    }

    return false;
}

int main(){
    string experssion="((a+b))";
    if(isDuplicate(experssion)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}