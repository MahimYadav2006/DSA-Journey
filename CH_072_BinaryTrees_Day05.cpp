#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left==NULL;
        this->right=NULL;
    }
}
    Node* solve(map<int,int>&mp,int in[],int post[],int &index,int inOrderStart,int inOrderEnd,int n){
        if(index<0 || inOrderStart>inOrderEnd){
            return NULL;
        }
        int element=post[index--];
        Node* root=new Node(element);
        int position=mp[element];
        root->right=solve(mp,in,post,index,position+1,inOrderEnd,n);
        root->left=solve(mp,in,post,index,inOrderStart,position-1,n);
        
        return root;
        

    }
Node *buildTree(int in[], int post[], int n) {
        int postOrderIndex=n-1;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
        Node* ans=solve(mp,in,post,postOrderIndex,0,n-1,n);
        return ans;
}

// // Wrong output // //
    Node* solve(map<int,int>&mp,int in[],int pre[],int &index,int inOrderStart,int inOrderEnd,int n){
        if(index>=n || inOrderStart>inOrderEnd){
            return NULL;
        }
        int element=pre[index++];
        Node* root=new Node(element);
        int position=mp[element];
        root->left=solve(mp,in,pre,index,inOrderStart,position-1,n);
        root->right=solve(mp,in,pre,index,position+1,inOrderEnd,n);
        return root;
        

    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
        Node* ans=solve(mp,in,pre,preOrderIndex,0,n-1,n);
        return ans;
    }
int main(){
    
}