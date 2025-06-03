#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first-1;
    int v=edges[i].second-1;
    adj[u].push_back(v);
  }
  int indegree[n]={0};
  vector<int> ans;
  // Initialising the indegree array
  for(auto i: adj){
    for(auto j: i.second){
      indegree[j]++;
    }
  }
  queue<int> q;
  for(int i=0;i<n;i++){
    if(indegree[i]==0){
      q.push(i);
    } 
  }
  int cnt=0;
  while(!q.empty()){
    int front=q.front();
    cnt++;
    q.pop();
    for(auto k: adj[front]){
      indegree[k]--;
      if(indegree[k]==0){
        q.push(k);
      }
    }
  }
  return !(cnt==n);
}
int main(){
    
}