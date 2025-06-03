#include<iostream>
#include<cmath>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
void insertAtHeadNode(int d,Node* &head){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void insertAtTailNode(Node* & tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* xyz=curr->next;
        curr->next=prev;
        prev=curr;
        curr=xyz;
    }
    return prev;
}
// struct Node* addTwoLists(struct Node* first, struct Node* second) {
//     first = reverse(first);
//     second = reverse(second);

//     int carry = 0;
//     int a = first->data + second->data;
//     carry = a / 10;
//     Node* head = new Node(a % 10);
//     Node* tail = head;
//     first = first->next;
//     second = second->next;

//     while (first != NULL || second != NULL) {
//         a = (first ? first->data : 0) + (second ? second->data : 0) + carry;
//         carry = a / 10;
//         int put = a % 10;
//         Node* temp = new Node(put);
//         tail->next = temp;
//         tail = temp;
//         if (first) first = first->next;
//         if (second) second = second->next;
//     }

//     // Handle remaining nodes in 'first' or 'second'
//     while (first != NULL) {
//         a = first->data + carry;
//         carry = a / 10;
//         int put = a % 10;
//         Node* temp = new Node(put);
//         tail->next = temp;
//         tail = temp;
//         first = first->next;
//     }

//     while (second != NULL) {
//         a = second->data + carry;
//         carry = a / 10;
//         int put = a % 10;
//         Node* temp = new Node(put);
//         tail->next = temp;
//         tail = temp;
//         second = second->next;
//     }

//     return reverse(head);
// }



    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {   first=reverse(first);
        second=reverse(second);
        // print(first);
        // print(second);
        int carry=0;
        int a=first->data+second->data;
        carry=a/10;
        Node* head=new Node(a%10);
        Node* tail=head;
        first=first->next;
        second=second->next;
        while(first!=NULL || second!=NULL){
            a=(first ? first->data : 0) + (second ? second->data : 0) + carry;
            carry=a/10;
            int put=a%10;
            Node* temp=new Node(put);
            tail->next=temp;
            tail=temp;
            if(first){
                first=first->next;
            }
            if(second){
                second=second->next;
            }
            // if(second==NULL){
            //     break;
            // }
        }
        // cout<<"HI "<<endl;
        while(first!=NULL){
            a=first->data+carry;
            carry=a/10;
            int put=a%10;
            Node* temp=new Node(put);
            tail->next=temp;
            tail=temp;
            first=first->next;
            // if(first==NULL){
            //     break;
            // }
        }
        while(second!=NULL){
            a=second->data+carry;
            carry=a/10;
            int put=a%10;
            Node* temp=new Node(put);
            tail->next=temp;
            tail=temp;
            second=second->next;
            // if(second==NULL){
            //     break;
            // }
        }
        while(carry!=0){
            Node* temp=new Node(carry);
            tail->next=temp;
            tail=temp;
            carry=carry/10;
        }
        // print(head);
        return reverse(head);

    }
int main(){
    Node* head1=new Node(2);
    Node* tail=head1;
    insertAtHeadNode(3,head1);
    insertAtHeadNode(0,head1);
    insertAtHeadNode(7,head1);
    insertAtHeadNode(7,head1);
    // insertAtHeadNode(4,head1);
    // insertAtTailNode(ta;
    // insertAtTailNode(tail,9);il,5)
    cout<<"Printing the current Linked List ";
    print(head1);
    // cout<<"Printing the reverse of linked list ";
    // Node* a=reverse(head1);
    // print(a);
    Node* head2=new Node(0);
    insertAtHeadNode(6,head2);
    insertAtHeadNode(6,head2);
    insertAtHeadNode(9,head2);
    insertAtHeadNode(2,head2);
    cout<<"Printing the second linked list ";
    print(head2);
    cout<<"Printing the resultant linked list ";
    Node * a=addTwoLists(head1,head2);
    print(a);

}