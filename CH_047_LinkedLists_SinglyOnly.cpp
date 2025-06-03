#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    // Destructor
    ~Node(){
        int value=this->data;
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is freed up with data value as "<<value<<endl;
    }
};
void insertAtHeadNode(Node* & Head ,int d){

    // Creation of new Node
    Node * temp=new Node(d);

    // Making the NULL of temp to be address of Head current Head Node
    temp->next=Head;

    // Head ki position ko officialy change karna
    Head=temp;

}
void insertAtTailNode(Node * &tail,int d){
    Node* temp=new Node(d);

    // Modifying the "next" part of the tail
    tail->next=temp;

    // Changing tail officially
    tail=temp;
}
void insertAtMiddleNode(Node* &tail,Node* &head,int position,int d ){
    // Checking if you want to add at head
    if(position==1){
        insertAtHeadNode(head,d);
        return;
    }
    Node *temp=head;
    for(int i=1;i<position;i++){
        temp=temp->next;
    }
    // Checking if you want to add at tail
    if(temp->next==NULL){
        insertAtTailNode(tail,d);
        return;
    }
    // Creation of the new node
    Node * IamNew=new Node(d);

    // Taking the address of next obj
    Node *just=temp->next;

    // Modifying the "next" variable of the temp to the newly created node
    temp->next=IamNew;

    // Modifying the "name" of newly created object
    IamNew->next=just;



}
void print(Node* &head){
    Node *temp=head;
    
    // Printing the value at current Node
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
void deleteNode(int position,Node * & head,Node * & tail){
    if(position==1){
        Node *temp=head;
        head=head->next;
        // Memory freeing
        temp->next=NULL;
        delete temp;
        return;
    }
    Node *curr=head;
    Node* prev=NULL;
    int cnt=1;
    while(cnt<position){
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    if(curr==tail){
        tail=prev;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    
}
int main(){
    Node* n1=new Node(5);
    Node *head=n1;
    Node *tail=n1;
    insertAtHeadNode(head,55);
    insertAtHeadNode(head,78);
    insertAtHeadNode(head,1008);
    insertAtTailNode(tail,12345);
    insertAtTailNode(tail,11);
    print(head);
    cout<<endl;
    insertAtMiddleNode(tail,head,4,455);
    insertAtMiddleNode(tail,head,7,655);
    // cout<<tail->data<<endl;
    // insertAtMiddleNode(head,1,455);
    insertAtTailNode(tail,23);
    print(head);cout<<endl;
    // deleteNode(1,head,tail);
    deleteNode(9,head,tail);
    cout<<tail->data<<endl;
    // deleteNode(5,head,tail);
    print(head);
}