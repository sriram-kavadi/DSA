#include<iostream>
using namespace std;

class BankAccount{
    private:
    int accountNumber;
    int balance;
    public:
    BankAccount(int acc,int ba){
        this->accountNumber=acc;
        this->balance=ba;
    }
    void deposit(int amount){
        this->balance=this->balance+amount;
    }
    void withdraw(int amount){
        if(this->balance-amount<=0){
            cout<<"less balance"<<endl;
            return;
        }
        this->balance=this->balance-amount;
    }
    void getBalnce(){
        cout<<"your balance: "<<this->balance<<endl;
    }
};

int main(){
    BankAccount b1(9238470924,7500);
    b1.getBalnce();
    b1.deposit(500);
    b1.getBalnce();
    b1.withdraw(10000);
    b1.getBalnce();
    return 0;
}