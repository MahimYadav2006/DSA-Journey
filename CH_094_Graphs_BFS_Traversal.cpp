#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>>mp;
    void makeGraph(int u,int v){
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    void printGraph(){
        for(int i=0;i<mp.size();i++){
            cout<<i<<" -> ";
            for(auto i:mp[i]){
                cout<<i<<", ";
            }
            cout<<endl;
        }
    }
};
void bfs(unordered_map<int,list<int>>mp){
    int n=mp.size();
    unordered_map<int,bool>visited;
    queue<int>q;
    q.push(0);
    visited[0]=true;
    // cout<<0<<" ";
    for(int i=0;i<n;i++){
        if(!visited[i]){
            while(!q.empty()){
                int node=q.front();
                cout<<node<<" ";
                q.pop();
                visited[node]=true;
                for(auto i:mp[node]){
                    if(!visited[i]){
                        visited[i]=true;
                        q.push(i);
                    }
                }
            }
        }
    }
}
int main(){
    Graph g;
    int n;
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.makeGraph(u,v);
    }
    g.printGraph();
    cout<<endl;
    bfs(g.mp);
}