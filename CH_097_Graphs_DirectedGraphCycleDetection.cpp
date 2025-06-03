#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    void print(){
        for(auto i: adj){
            cout<<i.first<<" ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
bool isCycle(int node,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,unordered_map<int,bool> &curr){
    curr[node]=true;
    visited[node]=true;
    for(auto i: adj[node]){
        if(!visited[i]){
            bool cycle=isCycle(i,adj,visited,curr);
            if(cycle){
                return true;
            }
        }
        else if(curr[i]==true){
            return true;
        }
    }
    curr[node]=false;
    return false;
};
int main(){
    Graph g;
    int n;
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.print();
    unordered_map<int,bool>visited;
    unordered_map<int,bool>curr;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool cycle=isCycle(i,g.adj,visited,curr);
            if(cycle){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}