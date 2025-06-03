#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,list<T>>g;
    // vector<vector<T>>M;
    void addEdge(T u,T v,bool isDirected){
        // u-> v ke beech me to aayega hi aayega ek node
        g[u].push_back(v);
        // Agar undirected hai to v->u ke beech me bhi ek edge aayega
        if(!isDirected){
            g[v].push_back(u);
        }
    }
    void print(){
        for(auto i: g){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
    // void addMatrix(T u , T v, bool isDirected){
    //     cout<<"HI "<<endl;
    //     M[u][v]=1;
    //     if(!isDirected){
    //         M[v][u]=1;
    //     }
    // }
    // void printMatrix(){
    //     for(int i=0;i<M.size();i++){
    //         for(int j=0;j<M[i].size();j++){
    //             cout<<M[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
};

// // Que 1 // //
// #include <bits/stdc++.h> 
// vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
//     // Write your code here.


//     vector<vector<int>> adj(n);
//     for(int i=0;i<n;i++){
//         adj[i].push_back(i);
//     }
//     for(int i=0;i<m;i++){
//         int u=edges[i][0];
//         int v=edges[i][1];
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     return adj;
// }

int main(){
    Graph<int> g;
    int n;
    cout<<"Please Enter number of nodes "<<endl;
    cin>>n;
    int m;
    cout<<"Please Enter number of edges "<<endl;
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,false);
        // g.addMatrix(u,v,false);
    }
    g.print();
    // g.printMatrix();
}


// // // //  Adjacency Matrix Approach // // // //
#include<iostream>
#include<vector>
using namespace std;
class Graph{
    public:
    int n;
    vector<vector<int>> arr;
    Graph(int n){
        this->n=n;
        arr.resize(n, vector<int>(n, 0));
    }
    void addEdge(int u,int v){
        arr[u][v]=1;
    }
    void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.print();
}


// Another approach using adjacency matrix
#include<iostream>
#include<vector>
using namespace std;
int main(){
    // Adjacency Matrix Representation of graphs
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>> adjMatrix(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjMatrix[u-1][v-1]=1;
        adjMatrix[v-1][u-1]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adjMatrix[i][j]<<" ";
        }cout<<endl;
    }
    
}