#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>
#include<queue>
#include<list>
#include<algorithm>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i].first;
		int v=edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	unordered_map<int,int> parent;
	unordered_map<int,bool> visited;
	queue<int> q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;
	while(!q.empty()){
		int front=q.front();
		q.pop();
		for(auto i: adj[front]){
			if(!visited[i]){
				parent[i]=front;
				visited[i]=true;
				q.push(i);
			}
		}
	}
	vector<int> ans;
	while(t!=-1){
		ans.push_back(t);
		t=parent[t];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
    
}