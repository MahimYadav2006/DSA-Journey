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
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL){
           return NULL;
       }
       if(root->data == n1 || root->data==n2){
           return root;
       }
       Node* left=lca(root->left,n1,n2);
       Node* right=lca(root->right,n1,n2);
       if(left!=NULL && right!=NULL){
           return root;
       }
       else if(left==NULL && right!=NULL){
           return right;
       }
       else if(left!=NULL && right==NULL){
           return left;
       }
       else{
           return NULL;
       }
    }
    void solve(Node* root,int sum,int &maxSum,int len,int &maxLen){
        if(root==NULL){
            if(len>maxLen){
                maxSum=sum;
                maxLen=len;
            }
            else if(len==maxLen){
                maxSum=max(maxSum,sum);
            }
            return;
        }
        sum+=root->data;
        solve(root->left,sum,maxSum,len+1,maxLen);
        solve(root->right,sum,maxSum,len+1,maxLen);
    }   
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum=0;
        int maxSum=INT_MIN;
        int len=0;
        int maxLen=0;
        solve(root,sum,maxSum,len,maxLen);
        return maxSum;
    }
int main(){
    
}