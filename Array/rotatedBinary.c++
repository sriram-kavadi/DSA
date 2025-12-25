#include<iostream>
using namespace std;

bool check(int *arr,int n,int key){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=(end-start)/2+start;
        if(arr[mid]==key){
            return true;
        }else if(arr[start]<=arr[mid]){
            if(arr[start]<=key&&arr[mid]>key){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else{
            if(arr[mid]<key&&arr[end]>=key){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return false;
}

int main(){
    int arr[]={9,11,13,15,17,19,1,3,5,7};
    int n=10;
    if(check(arr,n,3)){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}