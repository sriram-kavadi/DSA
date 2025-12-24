#include<iostream>
using namespace std;

class Shape{
    public:
    virtual void draw()=0;
};

class Circle:public Shape{
    public:
    void draw(){
        cout<<"Draw circle"<<endl;
    }
};

class Square :public Shape{
    public:
    void draw(){
        cout<<"Draw Square"<<endl;
    }
};

int main(){
    Circle c;
    c.draw();
    Square s;
    s.draw();
    return 0;
}