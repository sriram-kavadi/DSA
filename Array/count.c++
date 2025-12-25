#include<iostream>
using namespace std;

bool check(int *arr,int n){
    int count=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                if(arr[i]==arr[j]){
                    count++;
                    if(count>=2){
                        break;
                    }
                }
            }
        }
        if(count==1){
            return false;
        }
        count=1;
    }
}

int main(){
    int arr[]={1,2,3,4};
    int n=10;
    if(check(arr,n)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}