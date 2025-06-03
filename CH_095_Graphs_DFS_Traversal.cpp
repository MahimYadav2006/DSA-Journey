#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>>adjList;
    void makeEdge(int u,int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void printAdjacencyList(){
        for(auto i:adjList){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
void bfs(unordered_map<int,list<int>> &adjList){
    unordered_map<int,bool>visited;
    queue<int>q;
    q.push(1);
    for(int i=1;i<=adjList.size();i++){
        if(!visited[i]){
            while(!q.empty()){
                int topNode=q.front();
                visited[topNode]=true;
                cout<<topNode<<" ";
                q.pop();
                for(auto j: adjList[topNode]){
                    if(!visited[j]){
                        q.push(j);
                        visited[j]=true;
                    }
                }
            }
        }
    }
};
void dfsSolver(unordered_map<int,list<int>> &adjList,int node,unordered_map<int,bool>&visited){
    visited[node]=true;
    cout<<node<<" ";
    for(auto i: adjList[node]){
        if(!visited[i]){
            dfsSolver(adjList,i,visited);
        }
    }
}
void dfs(unordered_map<int,list<int>> &adjList){
    unordered_map<int,bool>visited;
    for(int i=1;i<adjList.size();i++){
        if(!visited[i]){
            dfsSolver(adjList,i,visited);
        }
    }
}
int main(){
    int n;
    int m;
    Graph g;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.makeEdge(u,v);
    }
    g.printAdjacencyList();
    bfs(g.adjList);
    cout<<endl;
    dfs(g.adjList);
    
}