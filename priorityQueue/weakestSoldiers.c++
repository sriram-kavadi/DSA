#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class WeakestSoliders{
    public:
    int soldiers;
    int civilians;
    int id;

    WeakestSoliders(int soldiers,int civilians,int id){
        this->soldiers=soldiers;
        this->civilians=civilians;
        this->id=id;
    }

    bool operator < (const WeakestSoliders &obj)const{
        if(this->civilians==obj.civilians){
            return this->id>obj.id;
        }
        return this->civilians<obj.civilians;
    }

};

void weakSoldiers(vector<vector<int>>vec,int k){
    priority_queue<WeakestSoliders>pq;
    int id=0;
    for(auto i:vec){
        int soliders=0;
        int civilians=0;
        for(auto j:i){
            if(j==0){
                civilians++;
            }

            if(j==1){
                soliders++;
            }

        }
        pq.push(WeakestSoliders(soliders,civilians,id));
        id++;
    }
    int i=1;
    while(!pq.empty()&&i<=k){
        cout<<pq.top().id<<" "<<pq.top().civilians<<" "<<pq.top().soldiers<<endl;
        pq.pop();
        i++;
    }

}

int main(){

    vector<vector<int>>vec={
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}
    };

    weakSoldiers(vec,2);

    return 0;
}