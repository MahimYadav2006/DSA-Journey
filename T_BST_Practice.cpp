#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void addElement(Node* &mainRoot,int value){
    if(mainRoot == NULL){
        mainRoot = new Node(value);
        return;
    } 
    Node* root = mainRoot;
    Node* prev = mainRoot;
    while(root != NULL){
        prev = root;
        if(value > root->data){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    if(prev->data < value){
        prev->right = new Node(value);
    }
    else prev->left = new Node(value);
}
Node* deleteNode(Node* root,int value){
    if(root == NULL) return NULL;
    if(root->data < value) return root->right = deleteNode(root->right,value);
    else if(root->data > value) return root->left = deleteNode(root->left,value);
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            // Find the inorder predecessor
            Node* pred = root->left;
            while (pred->right != NULL) {
                pred = pred->right;
            }
            root->data = pred->data;
            root->left = deleteNode(root->left, pred->data);  // Delete predecessor
            return root;
        }
    }
}
void printTree(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int currSize = q.size();
        for(int i=0;i<currSize;i++){
            Node* frontNode = q.front();
            q.pop();
            cout<<frontNode->data<<" ";
            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);
        }
        cout<<endl;
    }
}
int main(){
    Node* root = NULL;
    vector<int> temp = {10,1,3,2,4,8,5,9,6,7};
    for(int i=0;i<temp.size();i++){
        addElement(root,temp[i]);
    }
    root = deleteNode(root,10);
    printTree(root);
}