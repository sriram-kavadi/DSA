#include<iostream>
#include<string>
#include<vector>
using namespace std;

void merge(vector<string>&str,int start,int mid,int end){
    vector<string>temp;
    int i=start;
    int j=mid+1;
    while(i<=mid&&j<=end){
        int strCmp=str[i].compare(str[j]);
        if(strCmp<0){
            temp.push_back(str[i]);
            i++;
        }else{
            temp.push_back(str[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(str[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(str[j]);
        j++;
    }
    for(int k=start,x=0;k<=end;k++){
        str[k]=temp[x];
        x++;
    }
}

void mergeSort(vector<string>&str,int start,int end){
    if(start>=end){
        return;
    }
    int mid=start+(end-start)/2;
    mergeSort(str,start,mid);
    mergeSort(str,mid+1,end);
    merge(str,start,mid,end);
}

int main(){
    vector<string>str={"sun","earth","mars","mercury"};
    mergeSort(str,0,str.size()-1);
    for(string ch:str){
        cout<<ch<<" ";
    }
    return 0;
}