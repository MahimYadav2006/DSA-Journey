#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data,height;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=this->right=NULL;
        this->height=1;
    }
};
int getHeight(Node* root){
    if(!root){
        return 0;
    }
    return root->height;
}
int updateHeight(Node* root){
    return 1+max(getHeight(root->left),getHeight(root->right));
}
Node* leftRotate(Node* root){
    Node* child=root->right;
    Node* childLeft=child->left;
    child->left=root;
    root->right=childLeft;
    root->height=updateHeight(root);
    child->height=updateHeight(child);
    return child;
}
Node* rightRotate(Node* root){
    Node* child=root->left;
    Node* childRight=child->right;
    child->right=root;
    root->left=childRight;
    root->height=updateHeight(root);
    child->height=updateHeight(child);
    return child;
}
Node* insert(Node* root,int data){
    // Normal BST insertion

    if(!root){
        root= new Node(data);
    }
    else if(root->data<data){
        root->right=insert(root->right,data);
    }
    else{
        root->left=insert(root->left,data);
    }

    // // Updating the height
    root->height=1+max(getHeight(root->left),getHeight(root->right));

    // Checking the imbalancing
    int balance=getHeight(root->left)-getHeight(root->right);

    // Checking the type of imbalancing and calling their respective functions
    
    // Case 1-> LL imbalancing 
    if(balance>1 && root->left->data> data){
        return rightRotate(root);
    }
    
    // Case 2-> LR imbalancing 
    else if(balance>1 && root->left->data<data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    
    // Case 3 -> RR imbalancing 
    else if(balance<-1 && root->right->data<data){
        return leftRotate(root);
    }

    // Case 4-> RL imbalacing 
    else if(balance<-1 && root->right->data>data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    else{
        return root;
    }
}
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}
Node* deleteNode(Node* root,int data){
    if(!root){
        return NULL;
    }
    else if(root->data<data){
        root->right=deleteNode(root->right,data);
    }
    else if(root->data>data){
        root->left=deleteNode(root->left,data);
    }
    else{
        // Case 1 -> the node is leaf node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
            // Node* temp=root;
            // root=NULL;
            // delete temp;
        }
        // Only left child exists
        else if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        // Only right child exists
        else if(root->right!=NULL && root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        // Both the nodes exist
        else{
            // Finding the inorder predecessor
            Node* rightTree=root->right;
            while(rightTree->left){
                rightTree=rightTree->left;
            }
            root->data=rightTree->data;
            root->right=deleteNode(root->right,root->data);
        }

    }
        // Updating the heights
        root->height=updateHeight(root);
        // GetBalance
        int balance=getHeight(root->left)-getHeight(root->right);
        
        // Look for possible rotations

        // Left side
        if(balance>1){
            int newBalance=getHeight(root->left->left)-getHeight(root->left->right);
            if(newBalance>=0){
                // LL Imbalance
                return rightRotate(root);
            }
            else{
                // LR imbalance
                root->left=leftRotate(root->left);
                return rightRotate(root);
            }
        }
        // Right Side Imbalance
        else if(balance<-1){
            int newBalance=getHeight(root->right->left)-getHeight(root->right->right);
            if(newBalance>0){
                // RL imbalance 
                root->right=rightRotate(root->right);
                return leftRotate(root);
            }
            else{
                // RR imbalance 
                return leftRotate(root);
            }
        }
        else{
            return root;
        }
    // return root;
}
int main(){
    Node* root=NULL;
    root=insert(root,5);
    root=insert(root,10);
    root=insert(root,6);
    root=insert(root,70);
    root=insert(root,2);
    root=insert(root,45);
    root=insert(root,77);
    root=insert(root,17);
    root=insert(root,4);
    root=insert(root,66);
    // root=insert(root,10);
    // root=insert(root,20);
    // root=insert(root,30);
    root=deleteNode(root,10);
    levelOrder(root);
}











// // BST // //

// #include<iostream>
// #include<queue>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int data){
//         this->data=data;
//         this->left=NULL;
//         this->right=NULL;
//     }
// };
// void printTree(Node* root){
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//         Node* front=q.front();
//         q.pop();
//         if(front==NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout<<front->data<<" ";
//             if(front->left){
//                 q.push(front->left);
//             }
//             if(front->right){
//                 q.push(front->right);
//             }
//         }
//     }
// }
// Node* deleteNode(Node* root,int data){
//     if(root==NULL){
//         return NULL;
//     }
//     if(root->data<data){
//         root->right=deleteNode(root->right,data);
//         return root;
//     }
//     else if(root->data>data){
//         root->left=deleteNode(root->left,data);
//         return root;
//     }
//     else{
//         // Case 1-> if leaf node
//         if(root->left == NULL && root->right==NULL){
//             return NULL;
//         }
//         else if(root->left==NULL && root->right!=NULL){
//             return root->right;
//         }
//         else if(root->right==NULL && root->left!=NULL){
//             return root->left;
//         }
//         else{
//             // Find Inorder predecessor
//             Node* temp=root;
//             temp=temp->left;
//             while(temp->right!=NULL){
//                 temp=temp->right;
//             }
//             int nextToDelete=temp->data;
//             root->data=nextToDelete;
//             root->left=deleteNode(root->left,nextToDelete);
//         }
//         return root;
//     }
// }
// void printMinMax(Node* root){
//     Node* temp=root;
//     if(temp==NULL){
//         cout<<"The tree doesn't exist "<<endl;
//         return;
//     }
//     else{
//         while(temp->left!=NULL){
//             temp=temp->left;
//         }
//         cout<<"The minimum value is "<<temp->data<<endl;
//         temp=root;
//         while(temp->right!=NULL){
//             temp=temp->right;
//         }
//         cout<<"The maximum value is "<<temp->data<<endl;
//     }
// }
// Node* insert(Node* root,int data){
//         if(data==-1){
//             return NULL;
//         }
//     if(root==NULL){
//         root=new Node(data);
//     }
//     else{
//         if(root->data<data){
//             root->right=insert(root->right,data);
//         }
//         else{
//             root->left=insert(root->left,data);
//         }
//     }
//     return root;
// }

// int main(){
//     Node* root=NULL;
//     root=insert(root,5);
//     root=insert(root,3);
//     root=insert(root,7);
//     root=insert(root,2);
//     root=insert(root,1);
//     root=insert(root,6);
//     root=insert(root,8);
//     // root=deleteNode(root,5);
//     printMinMax(root);
//     printTree(root);
// }