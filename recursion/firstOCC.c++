#include<iostream>
#include<vector>
using namespace std;

int index(vector<int>vec,int target,int i){
    if(i==vec.size()-1){
        return -1;
    }
    if(vec[i]==target){
        int other=index(vec,target,i+1);
        if(other==-1){
            return i;
        }else{
            return other;
        }
    }
    return index(vec,target,i+1);
}

int main(){
    vector<int>vec={1,2,3,3,3,4};
    cout<<"check the target "<<index(vec,3,0)<<endl;
    return 0;
}