#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

pair<int,int> pairSum(vector<int>vec,int target){
    unordered_map<int,int>mp;
    for(int i=0;i<vec.size();i++){
        int check=target-vec[i];
        if(mp.count(check)==1){
            return make_pair(mp[check],i);
        }else{
            mp[vec[i]]=i;
        }
    }

    return make_pair(-1,-1);

}

int main(){
    vector<int>vec={1,2,7,11,15,5,9};
    int target=9;
    
    pair<int,int>result=pairSum(vec,21);

    cout<<result.first<<" "<<result.second<<endl;

    return 0;

}