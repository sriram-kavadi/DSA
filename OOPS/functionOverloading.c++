#include<iostream>
using namespace std;

class Print{
    public:
    void show(int n){
        cout<<n<<endl;
    }
    void show(string name){
        cout<<name<<endl;
    }
};

int main(){
    Print p1;
    p1.show(98);
    p1.show("nikhil");
    return 0;
}