#include<iostream>
using namespace std;

int main(){
    // int size;
    // cout<<"Enter size: ";
    // cin>>size;

    // int x=1;
    // int *arr=new int[size];
    // for(int i=0;i<size;i++){
    //     arr[i]=x;
    //     cout<<arr[i]<<" ";
    //     x++;
    // }
    // cout<<endl;

    int row,col;
    cout<<"Enter row: ";
    cin>>row;
    cout<<"Enter col: ";
    cin>>col;

    int **mattrix=new int*[row];
    for(int i=0;i<row;i++){
        mattrix[i]=new int[col];
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"Enter mattrix["<<i<<"]["<<j<<"]: ";
            cin>>mattrix[i][j];
        }
    }
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<mattrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}