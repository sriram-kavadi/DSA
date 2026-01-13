#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print(vector<int>str){
    int count=((str[0]|str[0])&str[0]);
    for(int i=0;i<str.size();i++){
        for(int j=0;j<str.size();j++){
            for(int k=0;k<str.size();k++){
                cout<<str[i]<<" "<<str[j]<<" "<<str[k]<<endl;
            }
        }
    }
    cout<<count<<endl;
}

int main(){
    print({1,4});
    return 0;
}