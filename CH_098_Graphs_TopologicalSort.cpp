#include<iostream>
#include<stack>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    void print(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
void dfs(unordered_map<int,list<int>> &adj,int *visited,stack<int> &st,int node){
    visited[node]=1;
    for(auto neighbour: adj[node]){
        if(visited[neighbour]==0){
            // visited[node]=1;
            dfs(adj,visited,st,neighbour);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(unordered_map<int,list<int>> adj,int v){
    int visited[v]={0};
    vector<int> ans;
    stack<int> st;
    for(int i=1;i<=v;i++){
        if(visited[i]==0){
            dfs(adj,visited,st,i);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


// vector<int> topologicalSort(unordered_map<int,list<int>> adj,int v){

// }
int main(){
    Graph g;
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.print();
    vector<int> ans=topologicalSort(g.adj,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}