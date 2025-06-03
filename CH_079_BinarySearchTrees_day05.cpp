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
Node* insertIntoBSTNode(Node* &root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBSTNode(root->right,d);
    }
    else{
        root->left=insertIntoBSTNode(root->left,d);
    }
    return root;
}
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while ((!q.empty()))
    {
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
        root=insertIntoBSTNode(root,data);
        cin>>data; 
    }
}
Node* makeFromLevelOrder(vector<int>lo){
    queue<Node*>q;
    int i=0;
    Node* root=new Node(lo[i++]);
    q.push(root);
    while(!q.empty() && i<lo.size()){
        Node* temp=q.front();
        q.pop();
        if(lo[i]!=-1){
            temp->left=new Node(lo[i]);
            q.push(temp->left);
            i++;
        }
        else{
            temp->left=NULL;
            i++;
        }
        if(lo[i]!=-1){
            temp->right=new Node(lo[i]);
            q.push(temp->right);
            i++;
        }
        else{
            temp->right=NULL;
            i++;
        }
    }
    return root;
}

// // Approach 1 // //

void inorder(Node* root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
bool isBST(Node* root){
    vector<int>in;
    inorder(root,in);
    for(int i=0;i<in.size()-1;i++){
        if(in[i]>in[i+1]){
            return false;
        }
    }
    return true;
}
int largetsBST(Node* root){
    if(root==NULL){
        return 0;
    }
    if(isBST(root)){
        return 1+(largetsBST(root->left)+largetsBST(root->right));
    }
    else{
        return max(largetsBST(root->left),largetsBST(root->right));
    }
}

// // Approach 2 // //
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
info solve(TreeNode* root,int &ans){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);
    info currNode;
    currNode.size=left.size+right.size+1;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data <right.mini)){
        currNode.isBST=true;
    }
    else{
        currNode.isBST=false;
    }
    if(currNode.isBST){
        ans=max(ans,currNode.size);
    }
    return currNode;
}
int largestBST(TreeNode* root){
    int ans=INT_MIN;
    info calm=solve(root,ans);
    return ans;

}
int main(){
    Node* root=NULL;
    vector<int>lo={1,2,3,4,-1,5,6,-1,7,-1,-1,-1,-1,-1,-1};
    root=makeFromLevelOrder(lo);
    levelOrderTraversal(root);
    // cout<<endl;
    // cout<<isBST(root)<<endl;
    cout<<largetsBST(root)<<endl;
}