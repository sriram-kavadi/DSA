#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}

int maxLength(vector<pair<int,int>>p){
    sort(p.begin(),p.end(),compare);

    int count=1;
    int currEnd=p[0].second;
    for(int i=1;i<p.size();i++){
        if(p[i].first>=currEnd){
            count++;
            currEnd=p[i].second;
        }
    }
    return count;
}

int main(){
    vector<pair<int,int>>p(5,make_pair(0,0));
    p[0]=make_pair(5,24);
    p[1]=make_pair(39,60);
    p[2]=make_pair(5,28);
    p[3]=make_pair(27,40);
    p[4]=make_pair(50,90);

    cout<<"max Chain "<<maxLength(p)<<endl;
    return 0;
}