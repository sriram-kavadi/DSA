#include<iostream>
using namespace std;

void print(int arr[][4],int n,int m){

    int srow=0,erow=n-1;
    int scol=0,ecol=m-1;
    while(srow<=erow && scol<=ecol){

        //top 
        for(int i=scol;i<=ecol;i++){
            cout<<arr[srow][i]<<" ";
        }

        //right
        for(int i=srow+1;i<=erow;i++){
            cout<<arr[i][ecol]<<" ";
        }

        //bottom
        for(int i=ecol-1;i>=scol;i--){
            if(srow==erow){
                break;
            }
            cout<<arr[erow][i]<<" ";
        }

        //left
        for(int i=erow-1;i>=srow+1;i--){
            if(scol==ecol){
                break; 
            }
            cout<<arr[i][ecol]<<" ";
        }

        srow++;
        erow--;
        scol++;
        ecol--;
    }
}

int main(){
    int mattrix[4][4]={{1,2,3,4},
                       {5,6,7,8},
                       {9,10,11,12},
                       {13,14,15,16}};
    print(mattrix,4,4);
    return 0;
}