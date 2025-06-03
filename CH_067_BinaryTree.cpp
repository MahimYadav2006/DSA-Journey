#include<iostream>
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
// // Practice // //
Node* buildTree(Node* root){
    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
}
// Node* buildTree(Node* root){
//     cout<<"Enter the data "<<endl;
//     int data;
//     cin>>data;
//     root=new Node(data);
//     if(data==-1){
//         return NULL;
//     }
//     cout<<"Enter the data to be inserted at the left of "<<root->data<<endl;
//     root->left=buildTree(root->left);
//     cout<<"Enter the data to be inserted at the right of "<<root->data<<endl;
//     root->right=buildTree(root->right);
//     return root;
// }

// Practice of level order traversal // //
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
// void levelOrderTraversal(Node* root){
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//         Node* temp=q.front();
//         // q.pop();
//         q.pop();
//         if(temp==NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout<<temp->data<<" ";
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//             }
//         }
        
//     }
// }


// // Practice of inOrderTraversal  // // 

void inOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
// void inOrderTraversal(Node* root){
//     if(root==NULL){
//         return;
//     }
//     inOrderTraversal(root->left);
//     cout<<root->data<<" ";
//     inOrderTraversal(root->right);
// }


// // Practice of preOrderTraversal // //

void preOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


// void preOrderTraversal(Node* root){
//     if(root==NULL){
//         return;
//     }
//     cout<<root->data<<" ";
//     preOrderTraversal(root->left);
//     preOrderTraversal(root->right);
// }

// Practcie of postOrderTraversal // //

void postOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}


// void postOrderTraversal(Node* root){
//     if(root==NULL){
//         return;
//     }
//     postOrderTraversal(root->left);
//     postOrderTraversal(root->right);
//     cout<<root->data<<" ";
// }

// Create from level Order traversal // // 

void createFromLevelOrder(Node* &root){
    queue<Node*>q;
    int data;
    cout<<"Enter the root data "<<endl;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        int leftData;
        cout<<"Enter the data to be entered at the left of the "<<temp->data<<endl;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter the data to be entered at the right of the "<<temp->data<<endl;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }
}


// void createFromLevelOrder(Node* &root){
//     queue<Node*>r;
//     int data;
//     cout<<"Enter data for root node "<<endl;
//     cin>>data;
//     root=new Node(data);
//     r.push(root);
//     while(!r.empty()){
//         Node* temp=r.front();
//         r.pop();
//         cout<<"Enter the data to be inserted at left of "<<temp->data<<endl;
//         int leftdata;
//         cin>>leftdata;
//         if(leftdata!=-1){
//             temp->left=new Node(leftdata);
//             r.push(temp->left);
//         }


//         cout<<"Enter the data to be inserted at right of "<<temp->data<<endl;
//         int rightdata;
//         cin>>rightdata;
//         if(rightdata!=-1){
//             temp->right=new Node(rightdata);
//             r.push(temp->right);
//         }
        
//     }
// }

// Creating a function to count number ogf leaf nodes // //

int noOfLeafNodes(Node* root){
    queue<Node*>q;
    int cnt=0;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        else if(temp->left == NULL && temp->right==NULL){
            cnt++;
        }
    }
    return cnt;
}

// int noOfLeafNodes(Node *root){
//     int cnt=0;
//     queue<Node*>q;
//     q.push(root);
//     while(!q.empty()){
//         Node *temp=q.front();
//         q.pop();
//         if(temp->left){
//             q.push(temp->left);
//         }
//         if(temp->right){
//             q.push(temp->right);
//         }
//         else if(temp->left==NULL && temp->right==NULL){
//             cnt++;
//         }
//     }
//     return cnt;
// }
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
int main(){
    Node* root=NULL;
    // root=buildTree(root);
    createFromLevelOrder(root);
    levelOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl<<endl;
    cout<<"Number of leaf nodes are "<<noOfLeafNodes(root)<<endl;
}