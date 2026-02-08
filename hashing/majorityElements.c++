#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void majorityElements(vector<int>vec){
    unordered_map<int,int>mp;
    for(auto i:vec){
        if(mp.count(i)){
            mp[i]++;
        }else{
            mp[i]=1;
        }
    }

    for(auto i:mp){
        if(i.second>vec.size()/3){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
}

int main(){
    vector<int>vec={1,3,2,5,1,3,1,5,1};

    majorityElements({1,2});

    return 0;

}
