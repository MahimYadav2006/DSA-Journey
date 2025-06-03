#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>>adj;
    void addEdge(int u,int v,bool directed=false){
        adj[u].push_back(v);
        if(!directed){
            adj[v].push_back(u);
        }
    }
    void print(){
        // cout<<"HI"<<endl;
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
string isCycle(unordered_map<int,list<int>> &adj){
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;
    queue<int>q;
    for(int i=1;i<=adj.size();i++){
        if(!visited[i]){
            q.push(i);
            parent[i]=-1;
            visited[i]=true;
            while(!q.empty()){
                int frontNode=q.front();
                visited[frontNode]=true;
                q.pop();
                for(auto j: adj[frontNode]){
                    if(visited[j] && parent[frontNode]==j){
                        continue;
                    }
                    else if(visited[j] && parent[frontNode]!=j){
                        return "YES";
                    }
                    else{
                        parent[j]=frontNode;
                        q.push(j);
                        visited[j]=true;
                    }
                }
            }
        }
    }
    return "NO";
}
bool isDFS(int node,int parent,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited){
    visited[node]=true;
    for(auto i: adj[node]){
        if(!visited[i]){
            bool cycle=isDFS(i,node,adj,visited);
            if(cycle==true){
                return true;
            }
        }
        else if(parent!=i){
            return true;
        }
    }
    return false;
}
string isCycleDFS(unordered_map<int,list<int>> &adj){
    unordered_map<int,bool>visited;
    for(int i=1;i<=adj.size();i++){
        if(!visited[i]){
            bool cycle=isDFS(i,-1,adj,visited);
            if(cycle==true){
                return "YES";
            }
        }
    }
    return "NO";
}
int main(){
    Graph g;
    int n;
    int e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.print();
    cout<<isCycle(g.adj)<<endl;
    cout<<isCycleDFS(g.adj)<<endl;
}