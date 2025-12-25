#include<iostream>
#include<algorithm>
using namespace std;

int product(int *arr,int n){
    int maxs=arr[0];
    int mins=arr[0];
    int current=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<0){
            swap(maxs,mins);
        }
        maxs=max(arr[i],arr[i]*maxs);
        mins=min(arr[i],arr[i]*mins);

        current=max(mins,maxs);
    }
    return current;
}

int main(){
    int arr[]={-2,0,-1};
    int n=3;
    int prod=product(arr,n);
    cout<<"Max product: "<<prod<<endl;
    return 0;
}