#include<iostream>
#include<string>
using namespace std;

bool isValid(string s) {
    int arr[3]={0};
    for(char ch:s){
        if(ch=='('||ch==')'){
            arr[0]++;
        }else if(ch=='{'||ch=='}'){
            arr[1]++;
        }else if(ch=='['||ch==']'){
            arr[2]++;
        }
    }
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<3;i++){
        if(arr[i]%2==1){
            return false;
        }
    }
    return true;
}

int main(){
    string s="(]";
    if(isValid(s)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}