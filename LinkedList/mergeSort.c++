#include<iostream>
#include<vector>
using namespace std;

void mergeSort(vector<int>&vec,int start,int mid,int end){
    vector<int>temp;
    int i=start;
    int j=mid+1;
    while(i<=mid&&j<=end){
        if(vec[i]<vec[j]){
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

    for(int i=start,k=0;i<=end;i++){
        vec[i]=temp[k];
        k++;
    }
}

void merge(vector<int>&vec,int start,int end){
    if(start>=end){
        return;
    }
    int mid=(end-start)/2+start;
    merge(vec,start,mid);
    merge(vec,mid+1,end);
    mergeSort(vec,start,mid,end);
}