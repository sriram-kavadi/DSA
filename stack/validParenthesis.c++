#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

bool valid(string s){
stack<char>stc;
for(auto i:s){
    if(i=='('||i=='{'||i=='['){
        stc.push(i);
    }else {
        if(stc.empty()){
            return false;
        }
        if((i=='}'&&stc.top()!='{')||(i==']'&&stc.top()!='[')||(i==')'&&stc.top()!='(')){
            return false;
        }

        stc.pop();
    }
}
return stc.empty();
}

int main(){
    string check=")()";
    if(valid(check)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}