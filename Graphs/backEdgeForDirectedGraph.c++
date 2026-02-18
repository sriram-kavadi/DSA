#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    public:
    int V;
    list<int>*li;
    bool isUndir;

    Graph(int n,bool isUndir=true){
        V=n;
        li=new list<int>[V];
        this->isUndir=isUndir;
    }

    void insert(int u,int v){ 
        li[u].push_back(v);//u-->v
        if(isUndir){//u--v
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

    bool isCycleHelper(int src,vector<bool>&vis,vector<bool>&recPath){
        vis[src]=true;
        recPath[src]=true;
        list<int>neighbor=li[src];
        for(auto i:neighbor){
            if(!vis[i]){
                if(isCycleHelper(i,vis,recPath)){
                    return true;
                }
            }else{
                if(recPath[i]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }

    bool isCycle(){
        vector<bool>vis(V,false);
        vector<bool>recPath(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycleHelper(i,vis,recPath)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    Graph graph(4,false);
    graph.insert(0,2);
    graph.insert(2,3);
    graph.insert(1,0);

    graph.print();

    if(graph.isCycle()){
        cout<<"Cycle Found"<<endl;
    }else{
        cout<<"Cycle Not Found"<<endl;
    }

    return 0;

}