#include<iostream>
#include<string>
using namespace std;

string removeDuplicates(string value,string ans,int i,bool chars[]){
    if(i==value.length()){
        return ans;
    }
    if(!chars[value[i]-'a']){
        ans+=value[i];
        chars[value[i]-'a']=true;
    }
    return removeDuplicates(value,ans,i+1,chars);
}

int main(){
    string value="appnacollege";
    string ans="";
    bool chars[26]={false};
    cout<<removeDuplicates(value,ans,0,chars);
    return 0;
}