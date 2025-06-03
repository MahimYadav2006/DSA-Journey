#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    unordered_map<int,list<int>> adj;
    // vector<int> indegree(v);
    int indegree[v]={0};
    for(int i =0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    // Indegree bnana
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    // for(int i=0;i<v;i++){
    //     cout<<indegree[i]<<" ";
    // };
    // 0 indegree waalo ko push karna
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);

        // Neighbour indegree udpate karna 
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}
int main(){
    
}