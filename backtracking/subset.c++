#include<iostream>
#include<vector>
#include<string>
using namespace std;

void subset(string str,string subStr){
    if(str.length()==0){
        cout<<subStr<<endl;
        return;
    }
    char ch=str[0];
    subset(str.substr(1,str.length()-1),subStr+ch);//yes
    subset(str.substr(1,str.length()-1),subStr);//No
}

int main(){
    string str="abc";
    subset(str,"");
    return 0;
}