#include<iostream>
#include<string>
using namespace std;

class User{
    //private
    int id;
    string password;
    //public
    public:
    string username;
    //constructor with parameters
    User(int id,string username){
        this->id=id;
        this->username=username;
    }
    //setter
    void setPassword(string password1){
        password=password1;
    }
    //getter
    string getPassword(){
        return password;
    }

};

int main(){
    User u1(1,"nikhil");
    u1.setPassword("hey**!");
    User u2(u1);
    cout<<u2.getPassword()<<endl;
    cout<<u1.getPassword()<<endl;
    return 0;
}