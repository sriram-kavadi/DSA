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

    void dfsHelper(int n,vector<bool>&vis){
        vis[n]=true;
        cout<<n<<" ";
        list<int>neighbor=li[n];
        for(auto i:neighbor){
            if(!vis[i]){
                dfsHelper(i,vis);
            }
        }

    }

    void dfs(){
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsHelper(i,vis);
            }
        }
        cout<<endl;
    }

    void bfsHelper(int n,vector<bool>&vis){
        queue<int>q;
        q.push(n);
        vis[n]=true;
        while(q.size()>0){
            int u=q.front();
            cout<<u<<" ";
            q.pop();
            list<int>neighbor=li[u];
            for(auto i:neighbor){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
    }

    void bfs(){
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bfsHelper(i,vis);
            }
        }
        cout<<endl;
    }



};

int main(){
    Graph graph(10);
    
    graph.insert(0,2);
    graph.insert(2,5);

    graph.insert(1,6);
    graph.insert(6,4);
    graph.insert(4,3);
    graph.insert(4,9);
    graph.insert(3,7);
    graph.insert(3,8);

    graph.print();

    graph.dfs();

    graph.bfs();

    return 0;
}