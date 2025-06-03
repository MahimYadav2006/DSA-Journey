#include<iostream>
#include<bits\stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insertNodeInBST(int data,Node* &root){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data<root->data){
        root->left=insertNodeInBST(data,root->left);
    }
    else{
        root->right=insertNodeInBST(data,root->right);
    }
    return root;
}

void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertNodeInBST(data,root);
        cin>>data;
    }
}
void inorder(int &ans,Node* root,int &count,int k){
    if(root==NULL){
        return;
    }
    inorder(ans,root->left,count,k);
    count=count+1;
    if(count==k){
        ans=root->data;
        return;
    }
    inorder(ans,root->right,count,k);
}
int kthSmallest(Node* root, int k) {
    int count=0;
    int ans=-1;
    inorder(ans,root,count,k);
    return ans;
}
int main(){
    Node* root=NULL;
    takeInput(root);
    levelOrderTraversal(root);
    cout<<kthSmallest(root,3)<<endl;
}