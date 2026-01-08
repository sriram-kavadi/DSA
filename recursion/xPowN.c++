#include<iostream>
using namespace std;

int xPowN(int x,int n){
    if(n==1){
        return x;
    }
    return x*xPowN(x,n-1);
}

int main(){
    cout<<"2 power 10 is "<<xPowN(2,10)<<endl;
    return 0;
}