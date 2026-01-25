#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int indianCoin(vector<int>coins,int v){
    int count=0;
    int i=0;
    while(i<coins.size()&&v!=0){
        if(coins[i]<=v){
            count++;
            v-=coins[i];
            cout<<coins[i]<<"+";
        }else{
            i++;
        }
    }
    cout<<endl;
    return count;
}

int main(){
    vector<int>coins={2000,500,100,50,20,10,5,2,1};
    cout<<indianCoin(coins,121);
    return 0;
}