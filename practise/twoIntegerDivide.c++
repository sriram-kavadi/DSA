#include<iostream>
using namespace std;

int divide(int dividend,int divisor){
    int ans=0;
    int n=dividend,d=divisor;
    while(n>=d){
        int count=0;
        while(n>=(d<<count+1)){
            count++;
        }
        ans+=(1<<count);
        cout<<(1<<count)<<endl;
        cout<<ans<<endl;
        n-=d<<count;
        cout<<n<<endl;
    }
    return ans;
}

int main(){
    cout<<"value: "<<divide(21,3);
    return 0;
}