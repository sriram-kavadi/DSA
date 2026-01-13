#include<iostream>
using namespace std;

int clearRange(int n,int i, int j){
    long long temp1=1;
    temp1=temp1<<(j-i+1);
    temp1-=1;
    temp1=temp1<<i;
    cout<<temp1<<endl;
    return (~temp1&n);
}

int main(){
    cout<<"Answer : "<<clearRange(121,4,5);
    return 0;
}