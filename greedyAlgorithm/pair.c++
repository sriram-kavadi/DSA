#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool toCompare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}

int main(){
    vector<pair<int,int>>act;
    act.push_back(make_pair(0,9));
    act.push_back(make_pair(1,3));
    act.push_back(make_pair(4,5));
    for(auto at:act){
        cout<<at.first<<","<<at.second<<endl;
    }
    sort(act.begin(),act.end(),toCompare);
    for(auto at:act){
        cout<<at.first<<","<<at.second<<endl;
    }
    return 0;
}