#include<iostream>
#include<vector>
using namespace std;

int find(vector<int>&nums,int target){
    int start=0,end=nums.size()-1;
    int mid=0;
    while(start<=end){
        mid=start+(end-start)/2;
        if(nums[mid]==target){
            return mid;
            break;
        }else if(nums[start]<=nums[mid]){
            if(nums[start]<=target&&target<=nums[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else{
            if(nums[mid]<=target&&target<=nums[end]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int>vec={1,0,1,1,1,1};
    int index=find(vec,0);
    cout<<"Index is "<<index<<endl;
    return 0;
}