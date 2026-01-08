#include<iostream>
using namespace std;

void print(int n){
    cout<<n<<" ";
    if(n==1){
        return;
    }
    print(n-1);
}

int main(){
    print(30);
    cout<<endl;
    return 0;
}