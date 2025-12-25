#include<iostream>
using namespace std;

int subarray(int *arr,int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum>max){
                max=sum;
            }
        }
        sum=0;

    }
    return max;
}

int main(){
    int arr[5]={1,2,3,4,5};
    int size=5;
    int max=subarray(arr,5);
    cout<<"max sum of an array : "<<max<<endl;
    return 0;
}