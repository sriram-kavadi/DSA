#include<iostream>
#include<vector>
using namespace std;

int partion(vector<int>&vec,int si,int ei){
    int i=si-1;
    int pivot=vec[ei];
    for(int j=si;j<ei;j++){
        if(vec[j]<=vec[pivot]){
            i++;
            swap(vec[i],vec[j]);
        }
    }
    i++;
    swap(vec[i],vec[ei]);
    return i;
}

void quickSort(vector<int>&vec,int si,int ei){
    if(si>=ei) return;
    int pivotIdx=partion(vec,si,ei);
    quickSort(vec,si,pivotIdx-1);
    quickSort(vec,pivotIdx+1,ei);
}

int main(){
    vector<int>vec={6,3,7,5,2,4};
    quickSort(vec,0,vec.size()-1);
    for(int i:vec){
        cout<<i<<" ";
    }
    return 0;
}