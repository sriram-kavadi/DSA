#include<iostream>
#include<string>
using namespace std;

bool check(string str1, string str2){
    if(str1==str2){
        return true;
    }
    int idxs[2];
    int count=0;
    for(int i=0;i<str1.length();i++){
        if(str1[i]!=str2[i]){
            if(count>=2){
                return false;
            }
            idxs[count]=i;
            count++;
        }
    }
    if(count!=2){
        return false;
    }
    swap(str2[idxs[0]],str2[idxs[1]]);
    if(str1==str2){
        return true;
    }else{
        return false;
    }
}

int main(){
    string str1="bank";
    string str2="knab";

    if(check(str1,str2)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}