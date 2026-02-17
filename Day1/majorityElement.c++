#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int largest(vector<int>vec){
    int ans=vec[0];
    int count=1;
    unordered_map<int,int>mp;

    for(auto i:vec){
        if(mp.count(i)==0){
            mp[i]=1;
        }else{
            mp[i]++;
            if(mp[i]>count){
                ans=i;
                count=mp[i];
            }
        }
    }
    return ans;
}

int main(){
    vector<int>vec={6,5,5};

    cout<<largest(vec)<<endl;

    return 0;
}
