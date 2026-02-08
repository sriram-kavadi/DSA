#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void iternaryFromTickets(unordered_map<string,string>mp){
    unordered_set<string>to;
    for(auto i:mp){
        to.insert(i.second);
    }
    string starting;

    for(auto i:mp){
        if(to.find(i.first)==to.end()){
            starting=i.first;
            break;
        }
    }
    cout<<starting<<"->";
    while(mp.count(starting)){
        cout<<mp[starting]<<"->";
        starting=mp[starting];
    }
    cout<<"END"<<endl;
}

int main(){
    unordered_map<string,string>mp;
    mp["chennai"]="bengaluru";
    mp["mumbai"]="delhi";
    mp["goa"]="chennai";
    mp["delhi"]="goa";

    iternaryFromTickets(mp);

    return 0;
    
}