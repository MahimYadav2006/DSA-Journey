#include<iostream>
#include<vector>
using namespace std;
// class DisjointSet{
//     vector<int> parent,rank;
//     public:
//     DisjointSet(int n){
//         rank.resize(n+1,0);
//         parent.resize(n+1);
//         for(int i=0;i<=n;i++){
//             parent[i] = i;
//         }
//     }
//     int find_Ult_Parent(int u){
//         if(u == parent[u]){
//             return u;
//         }
//         return parent[u] = find_Ult_Parent(parent[u]);
//     }
//     void unionByRank(int u,int v){
//         int pu = find_Ult_Parent(u);
//         int pv = find_Ult_Parent(v);
//         if(pu == pv){return;}
//         if(rank[pu] < rank[pv]){
//             parent[pu] = pv;
//         }
//         else if(rank[pu] > rank[pv]){
//             parent[pv] = pu;
//         }
//         else{
//             parent[pv] = pu;
//             rank[pu]++;
//         }
//     }
// };

// class DisjointSet{
//     vector<int> parent,size;
//     public:
//     DisjointSet(int n){
//         size.resize(n+1,0);
//         parent.resize(n+1);
//         for(int i=0;i<=n;i++){
//             parent[i] = i;
//         }
//     }
//     int find_Ult_Parent(int u){
//         if(u == parent[u]){
//             return u;
//         }
//         return parent[u] = find_Ult_Parent(parent[u]);
//     }
//     void unionByRank(int u,int v){
//         int pu = find_Ult_Parent(u);
//         int pv = find_Ult_Parent(v);
//         if(pu == pv){return;}
//         if(size[pu] < size[pv]){
//             parent[pu] = pv;
//             size[pv]+=size[pu];
//         }
//         else{
//             parent[pv] = pu;
//             size[pu]+=size[pv];
//         }
//     }
// };


class DisjointSet{
    vector<int> parent,size;
    public:
    DisjointSet(int n){
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int find_Ult_Parent(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = find_Ult_Parent(parent[u]);
    }
    void unionByRank(int u,int v){
        int pu = find_Ult_Parent(u);
        int pv = find_Ult_Parent(v);
        if(pu == pv){return;}
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }
};
int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    cout<<((ds.find_Ult_Parent(2) == ds.find_Ult_Parent(6))?"Same":"Not Same")<<endl;
    ds.unionByRank(1,4);
    cout<<((ds.find_Ult_Parent(2) == ds.find_Ult_Parent(6))?"Same":"Not Same")<<endl;

}