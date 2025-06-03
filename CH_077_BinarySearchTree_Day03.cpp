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
Node* insertNodeInBSTe(int data,Node* &root){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data<root->data){
        root->left=insertNodeInBSTe(data,root->left);
    }
    else{
        root->right=insertNodeInBSTe(data,root->right);
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
        root=insertNodeInBSTe(data,root);
        cin>>data;
    }
}

 // // Balanced BST // //


// void inorder(TreeNode<int>* root ,vector<TreeNode<int>*>&ans) {
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left,ans);
//     ans.push_back(root);
//     inorder(root->right,ans);
// }
// TreeNode<int>* insertIntoBSTNode(TreeNode<int>* &root, vector<TreeNode<int>*>& ans, int start, int end) {
//     if (start > end)
//         return nullptr;

//     int mid = start + (end - start) / 2;
//     TreeNode<int>* node = ans[mid];

//     // Insert node into the BST
//     root = node;

//     // Recursively insert nodes into left and right subtrees
//     root->left = insertIntoBSTNode(root->left, ans, start, mid - 1);
//     root->right = insertIntoBSTNode(root->right, ans, mid + 1, end);

//     return root;
// }

// TreeNode<int>* balancedBst(TreeNode<int>* root) {
//     vector<TreeNode<int>*>ans;
//     inorder(root,ans);
//     TreeNode<int>* ansRoot=NULL;
//     int start=0;
//     int end=ans.size()-1;
//     for(int i=0;i<ans.size();i++){
//         ans[i]->left=NULL;
//         ans[i]->right=NULL;
//         // cout<<ans[i]->data<<" ";
//     }
//     // cout<<endl;
//     // cout<<"The level order of final ans is "<<endl;
//     insertIntoBSTNode(ansRoot,ans,start,end);
//     // levelOrderTraversal(ansRoot);


//     return ansRoot;
// }


// // BST From PreOrder // //
// BinaryTreeNode<int>* solve(vector<int> &preorder,int min,int max,int &i){
//     if(i>=preorder.size()){
//         return NULL;
//     }
//     if(preorder[i]<min || preorder[i]>max){
//         return NULL;
//     }
//     BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[i++]);
//     root->left=solve(preorder,min,root->data,i);
//     root->right=solve(preorder,root->data,max,i);
//     return root;
// }
// BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
//     int min=INT_MIN;
//     int max=INT_MAX;
//     int i=0;
//     return solve(preorder,min,max,i);

// }

int main(){
    
}