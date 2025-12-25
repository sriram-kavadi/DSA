#include<iostream>
using namespace std;

int maxProfit(int *arr,int n){
    int bestBuy[n];
    bestBuy[0]=INT_MIN;
    int min=9999;
    for(int i=1;i<n;i++){
        
        if(arr[i]<min){
            min=arr[i];
        }
        if()
    }
}

int main(){
    int arr[]={7,6,4,3,1};
    int n=5;
    int maxP=maxProfit(arr,n);
    cout<<"Profit Earned: "<<maxP<<endl;
    return 0;
}