#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}

int ActivitySelection(vector<int>start,vector<int>end){
    vector<pair<int,int>>p;

    for(int i=0;i<start.size();i++){
        p.push_back(make_pair(start[i],end[i]));
    }

    sort(p.begin(),p.end(),compare);

    for(auto i:p){
        cout<<i.first<<" "<<i.second<<endl;
    }

    int count=0;
    int currEnd=p[0].second;
    for(int i=1;i<start.size();i++){
        if(p[i].first>=currEnd){
            count++;
            currEnd=p[i].second;
        }
    }
    return count;
}

int main(){
    vector<int>start={10,12,20};
    vector<int>end={20,25,30};
    cout<<ActivitySelection(start,end)<<endl;
    return 0;
}