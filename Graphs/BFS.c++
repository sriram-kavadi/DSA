#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    public:
    Graph(int n){
        V=n;
        l=new list<int>[V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u=0;u<V;u++){
            list<int>neighbors=l[u];
            cout<<u<<"-> ";
            for(auto i:neighbors){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }

    void BFS(queue<int>q,vector<bool>vis){
        q.push(0);
        vis[0]=true;
        while(q.size()>0){
            int u=q.front();
            cout<<u<<" ";
            q.pop();
            list<int>neighbors=l[u];
            for(int i:neighbors){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
        cout<<endl;
    }

    void dfs(int u,vector<bool>&vis){
        vis[u]=true;
        cout<<u<<" ";

        list<int>neighbors=l[u];

        for(auto i:neighbors){
            if(!vis[i]){
                dfs(i,vis);
            }
        }
    }
};

int main(){
    Graph graph(7);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(5,6);

    graph.print();

    queue<int>q;
    vector<bool>vis(7,false);

    graph.BFS(q,vis);

    graph.dfs(0,vis);


    return 0;
}