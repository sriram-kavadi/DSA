#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print(vector<int>str){
    int count=((str[0]|str[0])&str[0]);
    for(int i=0;i<str.size();i++){
        for(int j=0;j<str.size();j++){
            for(int k=0;k<str.size();k++){
                if(i==0&&j==0&&k==0){
                    continue;
                }
                count^=((str[i]|str[j])&str[k]);
            }
        }
    }
    cout<<count<<endl;
}

int main(){
    print({15,45,20,2,34,35,5,44,32,30});
    return 0;
}