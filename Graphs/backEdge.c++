#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    public:
    int V;
    list<int>*li;
    Graph(int n){
        V=n;
        li=new list<int>[V];
    }

    void insert(int u,int v){
        li[u].push_back(v);
        li[v].push_back(u);
    }

    void print(){
        for(int u=0;u<V;u++){
            cout<<u<<"-> [ ";
            list<int>neighbor=li[u];
            for(auto i:neighbor){
                cout<<i<<" ";
            }
            cout<<"]"<<endl;
        }
    }

    bool isCycleHelper(int src,int par,vector<bool>&vis){
        vis[src]=true;
        list<int>neighbor=li[src];
        for(auto i:neighbor){
            if(!vis[i]){
                if(isCycleHelper(i,src,vis)){
                    return true;
                }
            }else{
                if(i!=par){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(){
        vector<bool>vis(V,false);
        return isCycleHelper(0,-1,vis);
    }
};

int main(){
    Graph graph(5);
    
    graph.insert(0,1);
    graph.insert(0,2);
    graph.insert(0,3);
    graph.insert(1,2);
    graph.insert(3,4);

    graph.print();

    if(graph.isCycle()){
        cout<<"Existed:))"<<endl;
    }else{
        cout<<"Not Existed:??"<<endl;
    }


    return 0;
}