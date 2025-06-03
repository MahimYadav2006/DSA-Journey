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
    Node* createParentMapping(Node* root, int target, map<Node*, Node*>& nodeToParent) {
    Node* res = nullptr;
    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = nullptr;
    while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        if (front->data == target) {
            res = front;
        }
        if (front->left) {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right) {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(Node* root, map<Node*, Node*> nodeToParent) {
    map<Node*, bool> visited;
    queue<Node*> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    bool flag = false;
    while (!q.empty()) {
        int size = q.size();
        flag = false; // Reset flag for each level
        for (int i = 0; i < size; i++) {
            Node* front = q.front();
            q.pop();
            if (front->left && !visited[front->left]) {
                q.push(front->left);
                visited[front->left] = true;
                flag = true;
            }
            if (front->right && !visited[front->right]) {
                q.push(front->right);
                visited[front->right] = true;
                flag = true;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
                flag = true;
            }
        }
        if (flag) {
            ans++;
        }
    }
    return ans;
}

int minTime(Node* root, int target) {
    int ans = 0;
    map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMapping(root, target, nodeToParent);
    ans = burnTree(targetNode, nodeToParent);
    return ans;
}
int main(){
    
}