#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    // Constructor making
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    // Destructor
    // ~Node(){
    //     int value=this->data;
    //     if(this->next != NULL){
    //         delete next;
    //         next=NULL;
    //     }
    //     cout<<"Deleting node with value of data as "<<value<<endl;
    // }
};
void insertNode(Node* &tail,int prev,int data){
    // case 1 -> If the list is empty
    if(tail==NULL){
        Node *temp=new Node(data);
        tail=temp;
        temp->next=temp;
    }
    else{
        Node *current=tail;
        while(current->data!=prev){
            current=current->next;
        }
        Node *temp=new Node(data);
        temp->next=current->next;
        current->next=temp;
    }
}
void print(Node* tail){
    Node* temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
    
}
void deleteNode(Node* &tail,int value){
    Node* temp=tail->next;
    Node *prev=tail;
    while(temp->data !=value){
        prev=temp;
        temp=temp->next;
    }
    if(temp==tail){
        Node *forward=tail->next;
        // cout<<"Value at forward is "<<forward->data<<endl;
        // cout<<"data of temp is "<<temp->data<<endl;
        // cout<<"data of prev is "<<prev->data<<endl;
        // cout<<"data of tail is "<<tail->data<<endl;
        tail=forward;
        prev->next=tail;
        delete temp;
    }
    else{
        // cout<<"Hu"<<endl;
        prev->next=temp->next;
        delete temp;
    }
}
int main(){
    Node * tail=NULL;
    insertNode(tail,1008,1008);
    insertNode(tail,1008,88);
    insertNode(tail,88,3);
    insertNode(tail,88,455);
    insertNode(tail,88,21);
    insertNode(tail,3,1234);

    print(tail);
    // cout<<tail->data<<endl;
    deleteNode(tail,88);
    print(tail);
}