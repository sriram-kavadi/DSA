#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>&vec,int start,int end,int target){
    if(start>end){
        return -1;
    }
    int mid=(end-start)/2+start;
    if(vec[mid]==target){
        return mid;
    }else if(vec[mid]<target){
        return binarySearch(vec,mid+1,end,target);
    }else{
        return binarySearch(vec,start,mid-1,target);
    }
}

int main(){
    vector<int>vec={1,2,3,4,5,6,7};
    int target=0;
    cout<<"Found at "<<binarySearch(vec,0,vec.size()-1,target);
    return 0;
}