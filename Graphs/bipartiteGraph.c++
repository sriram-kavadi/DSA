#include<iostream>
#include<vector>
#include<queue>
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

    bool isBipartite(){
        vector<int>color(V,-1);
        queue<int>q;
        q.push(0);
        color[0]=0;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            list<int>neighbor=li[u];
            for(auto i:neighbor){
                if(color[i]==-1){
                    q.push(i);
                    color[i]=!color[u];
                }else{
                    if(color[i]==color[u]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    Graph graph(4);

    graph.insert(0,1);
    graph.insert(0,2);
    graph.insert(1,3);
    graph.insert(2,3);

    graph.print();

    if(graph.isBipartite()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;

}