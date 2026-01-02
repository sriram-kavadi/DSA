#include<iostream>
#include<string>
using namespace std;

int count(string str1){
    int counts=0;
    for(char ch:str1){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            counts++;
        }
    }
    return counts;
}

int main(){
    string data;
    cout<<"Enter you data: ";
    getline(cin,data);

    cout<<"Count of lowerCase vowels in data is : "<<count(data)<<endl;
    return 0;
}