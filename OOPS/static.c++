#include<iostream>
using namespace std;

void couts(){
    static int count=0;
    for(int i=0;i<10;i++){
        count++;
    }
    cout<<count<<endl;
}

int main(){
    couts();
    couts();
    couts();
}