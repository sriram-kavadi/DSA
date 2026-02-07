#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string,int>m;

    m["China"]=150;
    m["India"]=150;
    m["US"]=50;
    m["Nepal"]=10;
    m["America"]=0;

    for(pair<string,int>country:m){
        cout<<country.first<<","<<country.second<<endl;
    }

    if(m.count("Nepal")){
        cout<<"Nepal Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }

    m["Nepal"]=200;

    cout<<m["Nepal"]<<endl;

    return 0;

}