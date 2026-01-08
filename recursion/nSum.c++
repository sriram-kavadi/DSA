#include<iostream>
using namespace std;

int sum(int n){
    if(n==1){
        return 1;
    }
    return n+sum(n-1);
}

int main(){
    cout<<"Sum of 78 is "<<sum(78)<<endl;
    return 0;
}