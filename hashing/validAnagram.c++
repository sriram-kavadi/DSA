#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

unordered_map<char,int>mps(string s){
    unordered_map<char,int>mp;
    for(auto i:s){
        if(mp.count(i)){
            mp[i]++;
        }else{
            mp[i]=1;
        }
    }

    return mp;
}

bool checkAnagram(string s1,string s2){
    if(s1.size()!=s2.size()){
        return false;
    }

    unordered_map<char,int>s1Map=mps(s1);
    unordered_map<char,int>s2Map=mps(s2);
    for(int i=0;i<s1Map.size();i++){
        if(s1Map[i]!=s2Map[i]){
            return false;
        }
    }
    return true;

}

int main(){
    string s1="race";
    string s2="care";

    if(checkAnagram(s1,s2)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    return 0;

}