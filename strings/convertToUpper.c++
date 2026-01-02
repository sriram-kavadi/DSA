#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char word[]="ApPle";
    for(int i=0;i<strlen(word);i++){
        if(!(word[i]>=65&&word[i]<=97)){
            word[i]=word[i]-32;
        }
    }
    cout<<word<<endl;
    return 0;
}