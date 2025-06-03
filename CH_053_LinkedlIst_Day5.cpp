// // Que 1 // //

// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* prev;
//     Node* next;
//     Node(int data){
//         this->data=data;
//         this->next=NULL;
//         this->prev=NULL;
//     }
// };
// void insertAtHeadNode(Node* &head,int data){
//     Node* temp=new Node(data);
//     temp->next=head;
//     head->prev=temp;
//     head=temp;
// }
// void print(Node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }
// // Node * removeDuplicates(Node* head)
// // {
// //     Node* temp=head;
// //     if(head->next==NULL || head==NULL){
// //         return head;
// //     }
// //     while(temp!=NULL && temp->next!=NULL){
// //         Node* k=temp->next;
// //         if(temp->data==k->data){
// //             if(k->next!=NULL){
// //                 temp->next=k->next;
// //                 Node *z=k->next;
// //                 z->prev=temp;
// //             }
// //             else{
// //                 temp->next=NULL;
// //                 break;
// //             }
// //         }
// //         else{
// //             temp=temp->next;
// //         }
// //     }
// //     if(temp->data == temp->prev->data){
// //         temp->prev->next=NULL;
// //     }

// //     return head;
// // }
// Node* removeDuplicates(Node* head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     Node* curr=head;
//     while( curr->next!=NULL){
//         if(curr->data==curr->next->data){
//             Node* temp=curr->next->next;
//             delete curr->next;
//             curr->next=temp;
//             if(temp!=NULL){
//                 temp->prev=curr;
//             }
//         }
//         else{
//             curr=curr->next;
//         }
//     }
//     return head;
// }
// int main(){
//     Node* head=new Node(5);
//     // Node* a=removeDuplicates(head);
//     // print(a);
//     insertAtHeadNode(head,5);
//     insertAtHeadNode(head,5);
//     insertAtHeadNode(head,4);
//     insertAtHeadNode(head,2);
//     insertAtHeadNode(head,2);
//     insertAtHeadNode(head,2);
//     insertAtHeadNode(head,1);
//     insertAtHeadNode(head,1);
//     print(head);
//     Node* a=removeDuplicates(head);
//     print(a);
// }


// // Que 2 // //
#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    // ~Node(){
    //     cout<<"Deleting the node with value "<<this->data<<endl;
    //     delete this;
    // }
};
insertAtHeadNod(Node * &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
void print(Node* temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node *removeDuplicates(Node *head)
{
    unordered_map<int,bool>mp;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(mp[temp->data]!=true){
            mp[temp->data]=true;
            prev=temp;
            temp=temp->next;
        }
        else{
            prev->next=temp->next;
            Node* k=temp;
            temp=temp->next;
            delete k;
        }
    }
    return head;
}
int main(){
    
    Node* head=new Node(5);
    // Node* a=removeDuplicates(head);
    // print(a);
    // insertAtHeadNod(head,5);
    // insertAtHeadNod(head,12);
    // insertAtHeadNod(head,3);
    // insertAtHeadNod(head,25);
    // insertAtHeadNod(head,2);
    // insertAtHeadNod(head,25);
    // insertAtHeadNod(head,25);
    // insertAtHeadNod(head,2);
    // insertAtHeadNod(head,2);
    insertAtHeadNod(head,5);
    insertAtHeadNod(head,5);
    insertAtHeadNod(head,5);
    insertAtHeadNod(head,5);
    insertAtHeadNod(head,5);
    print(head);
    Node* a=removeDuplicates(head);
    print(a);

}