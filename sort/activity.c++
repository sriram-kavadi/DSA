#include<iostream>
#include <climits>   // or <limits.h>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int max=i;
        for(int j=i+1;j<n;j++){
            if(arr[max]<arr[j]){
                max=j;
            }
        }
        swap(arr[i],arr[max]);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int prev=i-1;
        while(prev>=0&&arr[prev]<current){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=current;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void coutingSort(int arr[],int n){
    int freq[10000];
    int minVal=INT_MAX;
    int maxVal=INT_MIN;
    for(int i=0;i<n;i++){
        minVal=min(minVal,arr[i]);
        maxVal=max(maxVal,arr[i]);
    }

    for(int i=0;i<n;i++){
        freq[i]++;
    }
    int j;
    for(int i=maxVal,j=0;i>=minVal;i--){
        while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={3,6,2,1,8,7,4,5,3,1};
    coutingSort(arr,10);
    return 0;
}