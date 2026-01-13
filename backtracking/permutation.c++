#include<iostream>
#include<vector>
#include<string>
using namespace std;

void permutation(string str,string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        permutation(str.substr(0,i)+str.substr(i+1,str.length()-1),ans+ch);
    }
}

int main(){
    permutation("abc","");
    return 0;
}