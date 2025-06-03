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
// bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // // Recursive Approach // //

    // if(root==NULL){
    //     return false;
    // }
    // if(root->data==x){
    //     return true;
    // }
    // else if(root->data<x){
    //     return searchInBST(root->right, x);
    // }
    // else{
    //     return searchInBST(root->left,  x);
    // }


    /// // Iterative approach // // 
    // BinaryTreeNode<int> * ptr=root;
    // while(ptr!=NULL){
    //     if(ptr->data==x){
    //         return true;
    //     }
    //     else if(ptr->data<x){
    //         ptr=ptr->right;
    //     }
    //     else{
    //         ptr=ptr->left;
    //     }
    // }
    // return false;
// }
int minValue(Node* root){
    Node* temp=root;
    while(temp!=NULL){
        if(temp->left==NULL){
            return temp->data;
        }
        temp=temp->left;
    }
    return -1;
}
int maxValue(Node* root){
    Node* temp=root;
    while(temp!=NULL){
        if(temp->right==NULL){
            return temp->data;
        }
        temp=temp->right;
    }
    return -1;
}
void printMaxMin(Node* root){
    Node* temp=root;
    while(temp!=NULL){
        if(temp->left==NULL){
            cout<<"The smallest value is "<<temp->data<<endl;
        }
        temp=temp->left;
    }
    temp=root;
    while(temp!=NULL){
        if(temp->right==NULL){
            cout<<"The largest value is "<<temp->data<<endl;
        }
        temp=temp->right;
    }
}
Node* deleteFromBST(Node* root,int d){
    if(root==NULL){
        return root;
    }
    if(root->data==d){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }
        // 1 child let say left one 
        else if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        // 1 child let right one is ok
        else if(root->right!=NULL && root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        // Both the nodes have child
        else{
            // int minimum = minValue(root->right);
            // root->data=minimum;
            // root->right=deleteFromBST(root->right,minimum);
            // return root;

            // Or we can do 
            int maximum = maxValue(root->left);
            root->data=maximum;
            root->left=deleteFromBST(root->left,maximum);
            return root;
        }
    }
    else if(root->data<d){
        root->right=deleteFromBST(root->right,d);
        return root;
    }
    else{
        root->left=deleteFromBST(root->left,d);
        return root;
    }
}
int main(){
    cout<<"Enter the data for root node: "<<endl;
    Node* root=NULL;
    takeInput(root);
    levelOrderTraversal(root);
    printMaxMin(root);
    Node* ans=deleteFromBST(root,10);
    cout<<endl;
    levelOrderTraversal(ans);
}