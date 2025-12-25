#include<iostream>
using namespace std;

int linearSearch(int *arr,int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[7]={2,5,34,1,66,45};
    int size=7;
    int key=66;
    int index=linearSearch(arr,size,key);
    if(index!=-1){
        cout<<"Found at: "<<index<<endl;
    }else{
        cout<<"Not Found:/"<<endl;
    }
    return 0;
}