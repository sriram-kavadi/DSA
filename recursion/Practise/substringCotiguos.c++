#include<iostream>
#include<string>
using namespace std;

long long countSubstrings(string s) {
    int charCount[26]={0};
    for(char ch:s){
        if(ch<='z'&&ch>='a'){
            charCount[ch-'a']++;
        }else if(ch<='Z'&&ch>='A'){
            charCount[ch-'A']++;
        }
    }
    int count=0;
    for(int i=0;i<26;i++){
        if(charCount[i]>0){
            count+=(charCount[i]*(charCount[i]+1)/2);
        }
    }
    return count;
}

int main(){
    cout<<"check: "<<countSubstrings("abcab");
    return 0;
}