#include<iostream>
#include<queue>
using namespace std;

class Car{
    public:
    int x1;
    int y1;
    int distance;
    Car(int x1,int y1){
        this->x1=x1;
        this->y1=y1;
        this->distance=(x1*x1)+(y1*y1);
    }

    bool operator < (const Car &obj)const{
        return this->distance>obj.distance;//min heap
    }
};

int main(){
    priority_queue<Car>c;
    
    c.push(Car(3,3));
    c.push(Car(5,-1));
    c.push(Car(-2,4));

    int k=2;
    int i=1;
    
    while(!c.empty()&&i<=k){
        cout<<c.top().distance<<endl;
        c.pop();
        i++;
    }

    return 0;

}