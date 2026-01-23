#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int currSize;
    int capacity;

    int f,r;

    public:
    Queue(int capacity){
        this->capacity=capacity;

        currSize=0;
        f=r=-1;
    }

    void push(int data){
        if(currSize==capacity){
            cout<<"Queue is full"<<endl;
            return;
        }

        r=(r+1)%capacity;
        arr[r]=data;
        currSize++;
    }

    void pop(){
        if(currSize==0){
            cout<<"Queue is Empty"<<endl;
            return;
        }

        f=(f+1)%capacity;
        currSize--;
    }

    int front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        return arr[f];
    }

    bool isEmpty(){
        return currSize==0;
    }

    void print(){
        if(f<=r){
            for(int i=f;i<=r;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }else{
            for(int i=f;i<capacity;i++){
                cout<<arr[i]<<" ";
            }
            for(int i=0;i<=r;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }

    ~Queue(){
        delete [] arr;
        arr=nullptr;
    }
};

