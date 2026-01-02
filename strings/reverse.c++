#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char word[]="nikhil";
    int n=strlen(word)-1;
    for(int i=0;i<=n/2;i++){
        swap(word[i],word[n-i]);
    }
    cout<<word<<endl;
    return 0;
}