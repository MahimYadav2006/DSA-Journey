#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>
#include<stack>
#include<climits>
#include<algorithm>
// // Link-> https://www.codingninjas.com/studio/problems/shortest-path-in-dag_8381897  // // 
void dfs(int node,unordered_map<int,bool>&visited,stack<int>&s,unordered_map<int,list<pair<int,int>>> &adj){
    visited[node]=true;
    for(auto j: adj[node]){
        int neighbour=j.first;
        if(!visited[neighbour]){
            visited[neighbour]=true;
            dfs(neighbour,visited,s,adj);
        }
    }
    s.push(node);
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int weight=edges[i][2];
        adj[u].push_back(make_pair(v,weight));
    }
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,s,adj);
        }
    }
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        arr[i]=INT_MAX;
    }
    arr[0]=0;
    while(!s.empty()){
        int front=s.top();
        s.pop();
        if(arr[front]==INT_MAX){
            arr[front]=-1;
        }
        else{
            for(auto j: adj[front]){
                int u=j.first;
                int v=j.second;
                // arr[j]=min(arr[j],arr[front]+v);
                arr[u]=(arr[u]<arr[front]+v)?arr[u]:arr[front]+v;
            }
        }
    }
    // vector<int> ans;
    return arr;
}

int main(){
    
}