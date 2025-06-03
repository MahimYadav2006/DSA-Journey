#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node *next;
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        this->prev=NULL;
        this->next=NULL;
        cout<<"Deleting node of data "<<value<<endl;
    }
};
void print(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getLength(Node* &head){
    Node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
void insertAtHeadNode(Node* &head ,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTailNode(Node* &tail,int d){
    Node* temp=new Node(d);
    temp->prev=tail;
    temp->next=NULL;
    if(tail!=NULL){
        tail->next=temp;
    }
    tail=temp;
}
void insertAtMiddleNode(Node* &head,Node* &tail,int position, int d){
    int length=getLength(head);
    if(position==1){
        insertAtHeadNode(head,d);
    }
    else if(position==length+1){
        insertAtTailNode(tail,d);
    }
    else{
        Node *temp=head;
        int cnt=1;
        while(cnt<position && temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        Node * reqd=new Node(d);
        Node * last=temp->prev;
        // Operations
        reqd->prev=last;
        reqd->next=temp;
        last->next=reqd;
        temp->prev=reqd;
    }
}
void deleteNode(Node* &head,Node* &tail,int position){
    Node *temp=head;
    int length=getLength(head);
    if(position==1){
        Node *first=temp->next;
        first->prev=NULL;
        head=temp->next;
        // Deletion
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
    else if(position==length){
        temp=tail;
        Node *last=temp->prev;
        last->next=NULL;
        tail=last;
        // Deletion
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
    else{
        Node* last;
        Node *first;
        int cnt=1;
        while(cnt<position){
            temp=temp->next;
            last=temp->prev;
            first=temp->next;
            cnt++;
        }
        last->next=first;
        first->prev=last;
        // Deleting the memory of temp
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;

    }
}
int main(){
    Node* n1=new Node(11);
    Node *head=n1;
    Node *tail=n1;
    insertAtHeadNode(head,5);
    insertAtHeadNode(head,1008);
    insertAtTailNode(tail,45);
    insertAtTailNode(tail,455);
    insertAtMiddleNode(head,tail,4,115);
    insertAtTailNode(tail,65);
    print(head);
    insertAtMiddleNode(head,tail,8,1000);
    print(head);
    deleteNode(head,tail,5);
    cout<<"Data of tail is "<<tail->data<<endl;
    cout<<"Data of head is "<<head->data<<endl;
    print(head);
    // cout<<getLength(head)<<endl;
}