#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main(){
    vector<int>vec={4,3,2,5,6,7,3,4,2,1};

    unordered_set<int>st(vec.begin(),vec.end());
    
    cout<<st.size()<<endl;

    return 0;
}