#include<iostream>
#include<stack>
#include<list>
#include<vector>
#include<unordered_map>
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
            for(auto j: i){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
}
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
void dfs(int node,unordered_map<int,bool> &visited,stack<int>&s,unordered_map<int,list<int>> &adj){
	visited[node]=true;
	for(auto nbr:adj[node]){
		if(!visited[nbr]){
			dfs(nbr,visited,s,adj);
		}
	}
	s.push(node);
}
void dfs2(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
	visited[node]=true;
	for(auto nbr: adj[node]){
		if(!visited[nbr]){
			dfs2(nbr,visited,adj);
		}
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}
	stack<int> s;
	unordered_map<int,bool> visited;
	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfs(i,visited,s,adj);
		}
	}
	// Create a transpose graph
	unordered_map<int,list<int>> transpose;
	for(int i=0;i<v;i++){
		visited[i]=false;
		for(auto nbr: adj[i]){
			transpose[nbr].push_back(i);
		}
	}
	// Now call dfs using above ordering
	int cnt=0; 
	while(!s.empty()){
		int top=s.top();
		s.pop();
		if(!visited[top]){
			cnt++;
			dfs2(top,visited,transpose);
		}
	}
	return cnt;
}
int main(){
    
}