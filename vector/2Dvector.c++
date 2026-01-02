#include<iostream>
#include<vector>
using namespace std;

vector<int> findError(vector<int>nums){
    bool oneCheck=true;
    vector<int>ans;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]&&oneCheck){
            ans.push_back(arr[i]);
            ans.push_back(arr[i]+1);
            oneCheck=false;
        }
    }
    return ans; 
}

int main(){
    vector<int>vec={1,2,2,4};

}