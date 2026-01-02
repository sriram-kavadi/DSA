#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>vec={1,2,3,4};
    cout<<&vec<<endl;
    cout<<vec.size()<<endl;
    cout<<vec.capacity()<<endl;
    for(int i=4;i<10;i++){
        vec.push_back(i);
    }
    cout<<&vec<<endl;
    cout<<vec.size()<<endl;
    cout<<vec.capacity()<<endl;
    return 0;
}