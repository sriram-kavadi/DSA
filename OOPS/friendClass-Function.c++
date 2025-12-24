#include<iostream>
using namespace std;

class A{
    string secret="secret data";
    friend class B;
};

class B{
    public:
    void showSecret(A &obj){
        cout<<obj.secret;

    }
};

int main(){
    A a;
    B b;
    b.showSecret(a);
    return 0;
}