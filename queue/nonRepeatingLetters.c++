#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void answer(string s){
    int chars[26]={0};
    queue<char>q;
    vector<char>ans;
    for(char ch:s){
        if(ch>='a'&&ch<='z'){
            chars[ch-'a']++;
        }

        if(ch>='A'&&ch<='Z'){
            chars[ch-'A']++;
        }

        q.push(ch);

        while(!q.empty()&&chars[q.front()-'a']!=1){
            q.pop();
        }

        if(q.empty()){
            ans.push_back('1');
        }else{
            ans.push_back(q.front());
        }
    }

    for(auto ch:ans){
        cout<<ch<<" ";
    }
    cout<<endl;
}

int main(){
    string s="aabccxb";
    answer(s);
    return 0;
}