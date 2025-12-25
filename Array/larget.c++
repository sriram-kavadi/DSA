#include<iostream>
using namespace std;

void largest(int arr[]){
    arr[0]=100;
}

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter arr["<<i<<"]: ";
        cin>>arr[i];
    }
    largest(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}