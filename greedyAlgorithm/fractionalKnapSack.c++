#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool toCompare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;

}

int main(){
    vector<pair<int,int>>p(3,make_pair(0,0));
    p[0]=make_pair(60,10);
    p[1]=make_pair(100,20);
    p[2]=make_pair(120,30);
    //display
    for(auto i:p){
        cout<<i.first<<" "<<i.second<<endl;
    }

    //perKg value
    for(int i=0;i<p.size();i++){
        int value=p[i].first;
        int weight=p[i].second;
        int perKg=value/weight;
        p[i]=make_pair(perKg,weight);
    }

    //display
    for(auto i:p){
        cout<<i.first<<" "<<i.second<<endl;
    }
    sort(p.begin(),p.end(),toCompare);
    int maxWeight=50;
    int mxValue=0;
    cout<<"Check"<<endl;
    //display
    for(auto i:p){
        cout<<i.first<<" "<<i.second<<endl;
    }

    for(auto i:p){
        if(maxWeight==0){
            break;
        }
        if(i.second<=maxWeight){
            int value=i.first*i.second;
            mxValue+=value;
            maxWeight-=i.second;
        }else{
            int value=i.first*maxWeight;
            mxValue+=value;
            maxWeight=0;
        }
    }
    cout<<"Max value: "<<mxValue<<endl;
    return 0;
}