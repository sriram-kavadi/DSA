#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>vec){
    int sum=0;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec.size();j++){
            for(int k=0;k<vec.size();k++){
                int value=(vec[i]|vec[j])&vec[k];
                sum=sum^value;
            }
        }
    }
    return sum;
}

int main(){
    vector<int>vec={15,45,20,2,34,35,5,44,32,30};
    cout<<"answer : "<<solve(vec);
    return 0;
}