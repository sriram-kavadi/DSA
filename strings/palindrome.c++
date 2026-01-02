#include<iostream>
#include<cstring>
using namespace std;

bool palindrome(char word[]){
    int n=strlen(word)-1;
    int start=0;
    while(start<n/2){
        if(word[start]!=word[n-start]){
            return false;
        }
        start++;
    }
    return true;
}

int main(){
    char name[]="racar";
    if(palindrome(name)){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"Not a palindrome"<<endl;
    }
}