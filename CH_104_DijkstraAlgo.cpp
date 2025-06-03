#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> distance(vertices);
    set<pair<int,int>> st;
    for(int i=0;i<vertices;i++){
        distance[i]=INT_MAX;
    }
    distance[source]=0;
    st.insert(make_pair(0,source));
    while(!st.empty()){

        // Fetch Top Node
        auto top=*(st.begin());
        int nodeDistance=top.first;
        int topNode=top.second;

        // remove top record now
        st.erase(st.begin());

        // Traverse the Neighbour Node        
        for(auto Neighbour: adj[topNode]){
            if(nodeDistance + Neighbour.second < distance[Neighbour.first]){
               
                // Search if it exists already
                auto record=st.find(make_pair(distance[Neighbour.first],Neighbour.first));
                
                // If we found the record
                if(record!=st.end()){
                    st.erase(record);
                }
               
                // Distance update
                distance[Neighbour.first]=nodeDistance+ Neighbour.second;
               
                // Update the record in set
                st.insert(make_pair(distance[Neighbour.first],Neighbour.first));
            }
        }
    }
    return distance;
}

int main(){
    
}