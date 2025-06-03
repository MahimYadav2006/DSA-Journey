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
vector<int> zigzagPrint(Node* root){
    queue<Node*>q;
    // vector<int>ans;
    q.push(root);
    q.push(NULL);
    // vector<int>ans;
    vector<int>t;
    int i=0;
    int j=0;
    bool leftToRight=true;
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp!=NULL){
            t.push_back(temp->data);
        }
        if(temp!=NULL){
            // q.push(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        else{
            if(!q.empty()){
                q.push(NULL);
            }
            if(!leftToRight){
                reverse(t.begin()+j,t.end());
                
            }
            j=i;
            leftToRight=!leftToRight;
        }
        if(temp!=NULL){
            i++;
        }
    }
    return t;
}
void traverseLeft(Node* root,vector<int>&ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }
}
void leafNodes(Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    leafNodes(root->left,ans);
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    leafNodes(root->right,ans);
}
void traverseRight(Node* root,vector<int>&ans){
    
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->right){
        traverseRight(root->right,ans);
    }
    else{
        traverseRight(root->left,ans);
    }
    
}
vector <int> boundary(Node *root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);
    // Traversing left
    traverseLeft(root->left,ans);
    // leafNodes
    leafNodes(root,ans);
    //Traversing right
    int j=ans.size();
    traverseRight(root->right,ans);
    reverse(ans.begin()+j,ans.end());
    return ans;

}
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int>topNodes;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node* newNode=temp.first;
            int hd=temp.second;
            if(!topNodes[hd]){
                topNodes[hd]=newNode->data;
            }
            if(newNode->left){
                q.push(make_pair(newNode->left,hd-1));
            }
            if(newNode->right){
                q.push(make_pair(newNode->right,hd+1));
            }
        }
        for(auto i:topNodes){
            ans.push_back(i.second);
        }
        return ans;
    }
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int>topNodes;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node* newNode=temp.first;
            int hd=temp.second;
            // if(!topNodes[hd]){
                topNodes[hd]=newNode->data;
            // }
            if(newNode->left){
                q.push(make_pair(newNode->left,hd-1));
            }
            if(newNode->right){
                q.push(make_pair(newNode->right,hd+1));
            }
        }
        for(auto i:topNodes){
            ans.push_back(i.second);
        }
        return ans;
    }
    vector<int> rightView(Node *root)
    {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int>topNodes;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node* newNode=temp.first;
            int level=temp.second;
            // if(!topNodes[hd]){
                topNodes[level]=newNode->data;
            // }
            if(newNode->left){
                q.push(make_pair(newNode->left,level+1));
            }
            if(newNode->right){
                q.push(make_pair(newNode->right,level+1));
            }
        }
        for(auto i:topNodes){
            ans.push_back(i.second);
        }
        return ans;
    }
vector<int> leftView(Node *root)
{
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int>topNodes;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node* newNode=temp.first;
            int level=temp.second;
            if(topNodes.find(level)== topNodes.end()){
                topNodes[level]=newNode->data;
            }
            if(newNode->left){
                q.push(make_pair(newNode->left,level+1));
            }
            if(newNode->right){
                q.push(make_pair(newNode->right,level+1));
            }
        }
        for(auto i:topNodes){
            ans.push_back(i.second);
        }
        return ans;
}
int main(){
    Node* root=NULL;
    createFromLevelOrder(root);
    // vector<int>v=zigzagPrint(root);
    vector<int>v=boundary(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}