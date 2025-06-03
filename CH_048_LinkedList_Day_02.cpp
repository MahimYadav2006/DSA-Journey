#include<bits\stdc++.h>
using namespace std;

// // /// /// // / / ///           QUESTION 1        // // / /// // / // // / //


//     template <typename T>
//     class LinkedListNode
//     {
//     public:
//         T data;
//         LinkedListNode<T> *next;
//         LinkedListNode(T data)
//         {
//             this->data = data;
//             this->next = NULL;
//         }
//     };

// void insertAtHeadNode(LinkedListNode<int>* &head,int d){
//     LinkedListNode<int>* temp=new LinkedListNode<int>(d);
//     temp->next=head;
//     head=temp;
// }
// void print(LinkedListNode<int>* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }
// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> * head){
//     LinkedListNode<int> * prev=NULL;
//     LinkedListNode<int>* curr=head;
//     while(curr!=NULL){
//         LinkedListNode<int>* xyz=curr->next;
//         curr->next=prev;
//         prev=curr;
//         if(xyz!=NULL){
//             curr=xyz;
//         }
//         else{
//             return curr;
//         }
//     }
// }
// int main(){
//     LinkedListNode<int>* head=new LinkedListNode<int>(1);
//     insertAtHeadNode(head,54);
//     insertAtHeadNode(head,6789);
//     insertAtHeadNode(head,109876);
//     // cout<<head->data<<endl;
//     print(head);
//     LinkedListNode<int>* head1=reverseLinkedList(head);
//     print(head1);
//     LinkedListNode<int>* h=head1->next;
//     // cout<<head1->data<<endl;
// }

// // // // // // // Que 2 // // // // // // // 
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
void print(Node* &head){
    Node *temp=head;
    
    // Printing the value at current Node
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}
void insertAtHeadNode(Node* & Head ,int d){

    // Creation of new Node
    Node * temp=new Node(d);

    // Making the NULL of temp to be address of Head current Head Node
    temp->next=Head;

    // Head ki position ko officialy change karna
    Head=temp;

}
int length(Node* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
Node *findMiddle(Node *head) {
    int len=length(head);;
    int ans=len/2;
    for(int i=1;i<=ans;i++){
        head=head->next;
    }
    return head;

}
int main(){
    Node *head=new Node(1);
    insertAtHeadNode(head,2);
    insertAtHeadNode(head,3);
    insertAtHeadNode(head,4);
    insertAtHeadNode(head,5);
    // insertAtHeadNode(head,6);
    print(head);
    Node* head1=findMiddle(head);
    print(head1);
}