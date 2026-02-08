#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int largestSubarray(vector<int>vec){
    unordered_map<int,int>mp;
    int sum=0;
    int currLargest=-1;
    for(int i=0;i<vec.size();i++){
        sum+=vec[i];
        if(mp.count(sum)){
            int idx=mp[sum];
            int currLen=i-idx;
            currLargest=max(currLargest,currLen);
        }else{
            mp[sum]=i;
        }
    }

    return currLargest;
}

int main(){
    vector<int>vec={15,-2,2,-8,1,7,10};

    cout<<largestSubarray(vec)<<endl;

    return 0;
}