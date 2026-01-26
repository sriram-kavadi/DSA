#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,int>mp;
    mp[10]=89;
    mp[88]=89;
    mp[12]=143;
    cout<<mp.count(12)<<endl;
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}