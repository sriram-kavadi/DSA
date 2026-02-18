#include<iostream>
#include<queue>
#include<list>
#include<vector>
using namespace std;

class Graph{
    public:
    list<int>*li;
    int V;

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
            list<int>neighbor=li[u];
            cout<<u<<"-> [ ";
            for(auto i:neighbor){
                cout<<i<<" ";
            }
            cout<<"]"<<endl;
        }
    }

    void bfs(int n){
        queue<int>q;
        vector<bool>vis(V,false);
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
        cout<<endl;
    }

    void dfs(int n,vector<bool>&vis){
        vis[n]=true;
        cout<<n<<" ";
        list<int>neighbor=li[n];

        for(auto i:neighbor){
            if(!vis[i]){
                dfs(i,vis);
            }
        }
    }

    bool hasPathHelperDfs(int src,int dest,vector<bool>&vis){
        if(src==dest){
            return true;
        }
        vis[src]=true;
        list<int>neighbor=li[src];
        for(auto i:neighbor){
            if(!vis[i]){
                hasPathHelperDfs(i,dest,vis);
            }
        }

        return false;
        
    }

    bool hasPathDfs(int src,int dest){
        vector<bool>vis(V,false);

        return hasPathHelperDfs(src,dest,vis);

    }

    bool hasPathBfs(int src,int dest){
        vector<bool>vis(V,false);
        queue<int>q;
        q.push(src);
        vis[src]=true;
        while(q.size()>0){
            int u=q.front();
            if(u==dest){
                return true;
            }
            q.pop();
            list<int>neighbor=li[u];
            for(auto i:neighbor){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
        return false;
    }

};

int main(){
    Graph graph(7);
    graph.insert(0,1);
    graph.insert(0,2);
    graph.insert(1,3);
    graph.insert(2,4);
    graph.insert(3,4);
    graph.insert(3,5);
    graph.insert(5,6);

    graph.print();

    graph.bfs(6);
    
    vector<bool>vis(7,false);

    graph.dfs(0,vis);
    cout<<endl;

    if(graph.hasPathDfs(0,9)){
        cout<<"Has Path"<<endl;
    }else{
        cout<<"No Path"<<endl;
    }

    if(graph.hasPathBfs(0,5)){
        cout<<"Has Path"<<endl;
    }else{
        cout<<"No Path"<<endl;
    }

    return 0;

}