#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void unionOfSets(unordered_set<int>st1,unordered_set<int>st2){
    unordered_set<int>st3(st1.begin(),st1.end());
    st3.insert(st2.begin(),st2.end());

    for(auto i:st3){
        cout<<i<<" ";
    }

    cout<<endl;

}


void insectionOfSets(unordered_set<int>st1,unordered_set<int>st2){
    if(st1.size()<st2.size()){
        for(auto i:st1){
            if(st2.find(i)!=st2.end()){
                cout<<i<<" ";
            }
        }
    }else{
        for(auto i:st2){
            if(st1.find(i)!=st1.end()){
                cout<<i<<" ";
            }
        }
    }
    cout<<endl;
}


int main(){
    vector<int>vec1={7,3,9};
    vector<int>vec2={6,3,9,2,9,4};

    unordered_set<int>st1(vec1.begin(),vec1.end());
    unordered_set<int>st2(vec2.begin(),vec2.end());

    unionOfSets(st1,st2);
    insectionOfSets(st1,st2);

    return 0;

}