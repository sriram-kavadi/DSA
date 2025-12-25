#include<iostream>
using namespace std;

int main(){
    int a=900;
    int *ptr=&a;
    int **pptr=&ptr;
    cout<<pptr<<"="<<&ptr<<endl;
    cout<<*pptr<<"="<<ptr<<endl;
    cout<<pptr<<endl;
    return 0;
}