#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>vec={2,7,11,15};
    int target=9;
    int idx1=0;
    int idx2=0;
    int start=0;
    int end=vec.size()-1;
    while(start<end){
        if(vec[start]+vec[end]==target){
            idx1=start;
            idx2=end;
            break;
        }else if(vec[start]+vec[end]>target){
            end--;
        }else{
            start++;
        }
    }   
    cout<<idx1<<"&"<<idx2<<endl;
    return 0;
}