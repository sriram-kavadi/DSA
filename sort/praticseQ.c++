#include<iostream>
using namespace std;

void sort(char arr[],int n){
    for(int i=1;i<n;i++){
        char current=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]<current){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=current;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
    char arr[6]={'f','b','a','e','c','d'};
    sort(arr,6);
    return 0;
}