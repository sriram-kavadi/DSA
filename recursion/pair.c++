#include<iostream>
using namespace std;

int pairs(int n){
    if(n==0||n==1){
        return 1;
    };
    return pairs(n-1)+(n-1)*pairs(n-2);
}

int main(){
    cout<<"No of ways: "<<pairs(4)<<endl;
    return 0;
}