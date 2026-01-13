#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&vec,int start,int mid,int end){
    int i=start;
    int j=mid+1;
    vector<int> temp;
    while(i<=mid&&j<=end){
        if(vec[i]>vec[j]){
            temp.push_back(vec[i]);
            i++;
        }else{
            temp.push_back(vec[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(vec[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(vec[j]);
        j++;
    }
    for(int m=0;m<temp.size();m++){
        vec[m+start]=temp[m];
    }
}

void mergeSort(vector<int>&vec,int start,int end){
    if(start >= end) return;
    int mid=(end-start)/2+start;
    mergeSort(vec,start,mid);
    mergeSort(vec,mid+1,end);
    merge(vec,start,mid,end);
}

int main(){
    vector<int>vec={6,3,7,5,2,4};
    mergeSort(vec,0,vec.size()-1);
    for(int i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}