#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int count(vector<int>vec,int k){
    unordered_map<int,int>mp;
    mp[0]=1;
    int sum=0;
    int ans=0;
    for(int i=0;i<vec.size();i++){
        sum+=vec[i];
        if(mp.count(sum-k)){
            ans+=mp[sum-k];
        }

        if(mp.count(sum)){
            mp[sum]++;
        }else{
            mp[sum]=1;
        }
    }

    return ans;

}

int main(){
    vector<int>vec={1,2,3};
    int k=3;

    cout<<count(vec,k)<<endl;

    return 0;
}