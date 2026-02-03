#include<iostream>
#include<queue>
using namespace std;

class Heap{
    vector<int>heap;
    public:

    void push(int value){
        heap.push_back(value);
        int childIdx=heap.size()-1;
        int parentIdx=(childIdx-1)/2;
        while(childIdx>=0&&parentIdx>=0&&heap[childIdx]>heap[parentIdx]){
            swap(heap[childIdx],heap[parentIdx]);
            childIdx=parentIdx;
            parentIdx=(childIdx-1)/2;
        }
    }

    void heapify(int id){
        if(id>=heap.size()){//for null nodes
            return;
        }
        
        int leftId=2*id+1;
        int rightId=2*id+2;
        int max=id;
        if(leftId<heap.size()&&heap[leftId]>heap[max]){
            max=leftId;
        }

        if(rightId<heap.size()&&heap[rightId]>heap[max]){
            max=rightId;
        }

        swap(heap[max],heap[id]);
        if(max!=id){//swapping with child
            heapify(max);
        }
    }

    void pop(){
        //step1
        swap(heap[0],heap[heap.size()-1]);
        //step2
        heap.pop_back();
        //step3
        heapify(0);

    }

    bool isEmpty(){
        return heap.size()==0;
    }

    int top(){
        return !isEmpty()? heap[0]:NULL;
    }

};

int main(){
    Heap h1;
    h1.push(8);
    h1.push(4);
    h1.push(5);
    h1.push(1);
    h1.push(2);
    h1.push(9);

    h1.display();

    cout<<h1.top()<<endl;

    h1.pop();

    h1.display();

    return 0;
}