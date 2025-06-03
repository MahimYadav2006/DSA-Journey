#include<iostream>
#include<queue>
#include<bits\stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int  d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
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
void createFromLevelOrder(Node* &root){
    queue<Node*>r;
    int data;
    cout<<"Enter data for root node "<<endl;
    cin>>data;
    root=new Node(data);
    r.push(root);
    while(!r.empty()){
        Node* temp=r.front();
        r.pop();
        cout<<"Enter the data to be inserted at left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            r.push(temp->left);
        }


        cout<<"Enter the data to be inserted at right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            r.push(temp->right);
        }
        
    }
}
int maxHeight(Node* root){

    // Approach 1 //


    // int cnt=0;
    // if(root==NULL){
    //     return 0;
    // }
    // queue<Node*>q;
    // q.push(root);
    // q.push(NULL);
    // while(!q.empty()){
    //     Node* temp=q.front();
    //     q.pop();
    //     if(temp==NULL){
    //         cnt++;
    //         if(!q.empty()){
    //             q.push(NULL);
    //         }
    //     }
    //     else{
    //         if(temp->left){
    //             q.push(temp->left);
    //         }
    //         if(temp->right){
    //             q.push(temp->right);
    //         }
    //     }
    // }
    // return cnt;

    // Approach 2 //
    if(root==NULL){
        return 0;
    }
    int h1=maxHeight(root->left);
    int h2=maxHeight(root->right);
    return max(h1,h2)+1;
}
    pair<bool,int>isBalancedFast(Node* root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        pair<bool,int>left=isBalancedFast(root->left);
        pair<bool,int>right=isBalancedFast(root->right);
        bool diff=abs(left.second-right.second)<=1;
        bool leftAns=left.first;
        bool rightAns=right.first;
        pair<bool,int>ans;
        ans.second=max(left.second,right.second)+1;
        if(leftAns && rightAns && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
pair<int,int>fastDiameter(Node* root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int>left=fastDiameter(root->left);
    pair<int,int>right=fastDiameter(root->right);
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;

    pair<int,int>ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}

int diameter(Node* root){
    // // Approach 1 // //
    // if(root==NULL){
    //     return 0;
    // }
    // int op1=diameter(root->left);
    // int op2=diameter(root->right);
    // int op3=maxHeight(root->left)+1+maxHeight(root->right);
    // return max(max(op1,op2),op3);

    // // Approach 2 // // 
    return fastDiameter(root).first;
}
    pair<bool,int>fastIsSumTree(Node* root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        else if(root->left==NULL && root->right==NULL){
            pair<bool,int>p=make_pair(true,root->data);
            return p;
        }
        pair<bool,int>leftSum=fastIsSumTree(root->left);
        pair<bool,int>rightSum=fastIsSumTree(root->right);
        bool left=leftSum.first;
        bool right=rightSum.first;
        bool condn=(leftSum.second+rightSum.second)==root->data;
        pair<bool,int>ans;
        if(left && right && condn ){
            ans.first=true;
            ans.second=2*root->data;
        }
        else{
            // ans.second=leftSum.second+ rightSum.second;
            ans.first=false;
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
        return fastIsSumTree(root).first;
    }
// 1 2 -1 -1 3 -1 -1
int main(){
    Node* root=NULL;
    createFromLevelOrder(root);
    levelOrderTraversal(root);
    cout<<isSumTree(root);
    // cout<<"The maximum height of the given binary tree is "<<maxHeight(root)<<endl;
    // cout<<"The diameter of the given tree is "<<diameter(root)<<endl;
    // cout<<isBalanced(root)<<endl;
}