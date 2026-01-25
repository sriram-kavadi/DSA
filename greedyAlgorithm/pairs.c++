#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<pair<int,int>>p(3,make_pair(0,0));

    p[0]=make_pair(60,100);
    p[2]=make_pair(100,20);
    p[3]=make_pair(120,30);

    for(auto i:p){
        cout<<i.first<<" "<<i.second<<endl;
    }

    sort(p.begin(),p.end(),toChange1);

    for(auto i:p){
        cout<<i.first<<" "<<i.second<<endl;
    }
    sort(p.begin(),p.end(),toChange);
    for(auto i:p){
        cout<<i.first<<" "<<i.second<<endl;
    }

    for(auto i:p){
        cout<<i.first<<" "<<i.second<<endl;
    }

    for(auto i:p){
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
    
}