#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>
void dfs(int node,int parent,int &timer,vector<int> &disc,vector<int> &low,vector<vector<int>> &result, unordered_map<int,list<int>>& adj,unordered_map<int,bool> &visited){
    visited[node]=true;
    disc[node]=timer;
    low[node]=timer;
    timer++;
    // Now going to neighbours
    for(auto nbr: adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!visited[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,visited);
            low[node]=min(low[node],low[nbr]);
            // Now check if edges is brodge or not
            if(low[nbr]> disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            // Matlab agar mai phele se visit kr chuka hu aur vo parent bhi nhi hai to matlab vo ek backedge hai
            low[node]=min(low[node],disc[nbr]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer=0;
    vector<int> disc(v);
    vector<int> low(v);
    unordered_map<int,bool>visited;
    int parent=-1;
    for(int i=0;i<v;i++){
        disc[i]=-1;
        low[i]=-1;
    }
    vector<vector<int>> result;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,parent,timer,disc,low,result,adj,visited);
        }
    }
    return result;
}
int main(){
    
}