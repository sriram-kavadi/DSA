#include<iostream>
using namespace std;

int expo(int num,int pow){
    int temp=num,mul=0;
    while(pow){
        int bit=pow&1;
        cout<<temp<<" ";
        mul+=bit*temp;
        pow=pow>>1;
        temp*=temp;
    }
    return mul;
}

int main(){
    cout<<"Value: "<<expo(3,5)<<endl;
    return 0;
}