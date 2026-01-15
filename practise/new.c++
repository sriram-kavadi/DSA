#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>vec={6,5,4,6};
    int x=0;
    for(auto i:vec){
        x^=i;
    }
    vector<int>prem;
    for(int i=1;i<vec.size();i=i+2){
        x^=vec[i];
    }
    prem.push_back(x);
    for(int i=1;i<=vec.size();i++){
        prem.push_back(prem[i-1]^vec[i-1]);
    }

    for(auto i:prem){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
