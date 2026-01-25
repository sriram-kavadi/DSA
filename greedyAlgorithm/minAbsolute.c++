#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int minAbsolute(vector<int>a,vector<int>b){
    sort(a.begin(),a.end()); //o(nlogn)
    sort(b.begin(),b.end()); //o(nlogn)
    int n=a.size();
    int count=0;
    for(int i=0;i<n;i++){
        count+=abs(a[i]-b[i]); //o(n)
    }
    return count;
}

//timeComplexity : o(nlogn)
//spaceComplexity : o(1)

int main(){
    vector<int>a={4,1,8,7};
    vector<int>b={2,3,6,5};
    cout<<"Min Absolute is "<<minAbsolute(a,b)<<endl;
    return 0;
}