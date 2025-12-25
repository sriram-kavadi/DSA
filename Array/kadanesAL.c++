#include<iostream>
using namespace std;

int subarray(int *arr,int n){
    int max=arr[0];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>max){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return max;
}

int main(){
    int arr[6]={2,-3,6,-5,4,2};
    int size=6;
    int max=subarray(arr,6);
    cout<<"max sum of an array : "<<max<<endl;
    return 0;
}