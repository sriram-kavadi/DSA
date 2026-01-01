#include<iostream>
using namespace std;

int sumDiagonal(int arr[][3],int n,int m){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i][i]+arr[i][n-1-i];
    }
    if(n%2==1){
        return sum-arr[n/2][m/2];
    }
    return sum;
}

int main(){
    int mattrix[3][3]={{1,2,3},
                       {5,6,7},
                       {9,10,11},};
    cout<<"Sum of the diagonals : "<<sumDiagonal(mattrix,3,3)<<endl;
    return 0;
}