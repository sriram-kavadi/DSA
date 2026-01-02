#include<iostream>
#include<string>
using namespace std;

bool check(string str1,string str2){
    if(str1.length()!=str2.length()){
        return false;
    }
    int characters[26]={0};
    for(char ch:str1){
        characters[ch-'a']++;
    }

    for(char ch:str2){
        if(characters[ch-'a']==0){
            return false;
        }
        characters[ch-'a']--;
    }
    return true;
}

int main(){
    string str1="anagram";
    string str2="nagaaram";
    if(check(str1,str2)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}