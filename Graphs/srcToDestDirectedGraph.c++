#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<string>
using namespace std;

class Graph{
    public:
    int V;
    list<int>*li;
    bool isDirected;
    Graph(int n,bool isDirected=false){
        V=n;
        li=new list<int>[V];
        this->isDirected=isDirected;
    }

    void insert(int u,int v){
        li[u].push_back(v);
        if(!isDirected){
            li[v].push_back(u);
        }
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

    void srcToDestHelper(int src,int dest,vector<bool>&vis,string path){
        if(src==dest){
            cout<<path<<dest<<endl;
            return;
        }

        vis[src]=true;
        path += to_string(src) + " ";
        list<int>neighbor=li[src];
        for(auto i:neighbor){
            if(!vis[i]){
                srcToDestHelper(i,dest,vis,path);
            }
        }
        vis[src]=false;
    }

    void srcToDest(int src,int dest){
        vector<bool>vis(V,false);
        string path="";
        srcToDestHelper(src,dest,vis,path);
    }
};


int main(){
    Graph graph(6,true);
    
    graph.insert(5,0);
    graph.insert(5,2);
    graph.insert(0,3);
    graph.insert(2,3);
    graph.insert(3,1);
    graph.insert(4,0);
    graph.insert(4,1);

    graph.print();

    graph.srcToDest(5,1);


    return 0;

}