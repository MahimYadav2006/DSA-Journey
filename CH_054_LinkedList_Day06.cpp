#include<iostream>
using namespace std;
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };
insertAtTailNode(int d,Node<int>* &tail){
    Node<int>* temp=new Node<int>(d);
    tail->next=temp;
    tail=temp;
}
void print(Node<int>* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}


 // // // // Approach 1 // // // //


// Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
// {   
//     Node<int>* faltu=new Node<int>(0);
//     Node<int>* ans=faltu;
//     while(first!=NULL || second!=NULL){
//         // cout<<"HI"<<endl;
//         if(first->data>second->data){
//             Node<int>* temp=new Node<int>(second->data);
//             faltu->next=temp;
//             faltu=temp;
//             // insertAtTailNode(second->data,faltu);
//             second=second->next;
//             // cout<<"Inserted "<<faltu->data<<endl;
//             if(second==NULL){
//                 break;
//             }
//         }
//         else{
//             Node<int>* temp=new Node<int>(first->data);
//             faltu->next=temp;
//             faltu=temp;
//             // insertAtTailNode(first->data,faltu);
//             first=first->next;
//             // cout<<"Inserted "<<faltu->data<<endl;
//             if(first==NULL){
//                 break;
//             }
//         }
//     }
//     // cout<<"BHALLU"<<endl;
//     while(first!=NULL){
//         Node<int>* temp=new Node<int>(first->data);
//         faltu->next=temp;
//         faltu=temp;
//         first=first->next;
//         // cout<<"Inserted "<<faltu->data<<endl;
//     }
//     while(second!=NULL){
//         Node<int>* temp=new Node<int>(second->data);
//         faltu->next=temp;
//         faltu=temp;
//         second=second->next;
//         // cout<<"Inserted "<<faltu->data<<endl;
//     }
//     return ans->next;
// }


// // // // Approach 2 // // // //
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second){
    if(first==NULL){
        return second;
    }
    else if(second==NULL){
        return first;
    }
    Node<int>* ans=first;
    Node<int>* prev=first;
    Node<int>* curr=first->next;
    Node<int>* tamma=second;
    if(second->data<prev->data){
        Node<int>* k=second->next;
        second->next=ans;
        ans=second;
        second=k;
    }
    while(curr!=NULL || second!=NULL){
        if(second->data <=curr->data && second->data>=prev->data){
            // cout<<"Inserting "<<second->data<<" between "<<prev->data<<" and "<<curr->data<<endl;
            Node<int>* temp=second->next;
            prev->next=second;
            second->next=curr;
            prev=second;
            second=temp;
        }
        else{
            prev=curr;
            if(curr->next!=NULL){
                curr=curr->next;
            }
            else{
                curr->next=second;
                break;
            }
        }
    }
    return ans;
}

int main(){
    Node<int>* first=new Node<int>(5);
    Node<int>* second=new Node<int>(1);
    Node<int>* firstTail=first;
    Node<int>* secondTail=second;
    insertAtTailNode(-1,firstTail);
    // insertAtTailNode(4,firstTail);
    // insertAtTailNode(6,firstTail);
    // insertAtTailNode(8,firstTail);
    // // // // Filling second list // // // //
    // insertAtTailNode(2,secondTail);
    insertAtTailNode(3,secondTail);
    insertAtTailNode(6,secondTail);
    insertAtTailNode(10,secondTail);
    insertAtTailNode(-1,secondTail);
    // insertAtTailNode(7,secondTail);
    // insertAtTailNode(8,secondTail);
    // insertAtTailNode(9,secondTail);
    print(first);
    print(second);
    Node<int>* ans=sortTwoLists(first,second);
    print(ans);



}




// // // // //   Que 2 // // // //
// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;

//     Node(int data){
//         this->data=data;
//         this->next=NULL;
//     }

//     // Destructor
//     ~Node(){
//         int value=this->data;
//         if(this->next != NULL){
//             delete next;
//             this->next=NULL;
//         }
//         cout<<"Memory is freed up with data value as "<<value<<endl;
//     }
// };
// void insertAtHeadNode(Node* & Head ,int d){

//     // Creation of new Node
//     Node * temp=new Node(d);

//     // Making the NULL of temp to be address of Head current Head Node
//     temp->next=Head;

//     // Head ki position ko officialy change karna
//     Head=temp;

// }
// void print(Node* &head){
//     Node *temp=head;
    
//     // Printing the value at current Node
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }

// }

// // // Approach 1 // //
// // Node* sortList(Node *head){
// //     int two=0;
// //     int one =0;
// //     int zero=0;
// //     Node* temp=head;
// //     while(temp!=NULL){
// //         if(temp->data==0){
// //             zero++;
// //         }
// //         else if(temp->data==1){
// //             one++;
// //         }
// //         else{
// //             two++;
// //         }
// //         temp=temp->next;
// //     }
// //     temp=head;
// //     int a=0;
// //     int b=0;
// //     int c=0;
// //     while(temp!=NULL){
// //         while(a<zero){
// //             temp->data=0;
// //             temp=temp->next;
// //             a++;
// //         }
// //         while(b<one){
// //             temp->data=1;
// //             temp=temp->next;
// //             b++;
// //         }
// //         while(c<two){
// //             temp->data=2;
// //             temp=temp->next;
// //             c++;
// //         }
// //     }
// //     return head;
// // }


// // // Approach 2 // //

// Node* sortList(Node *head){
//     Node* zerohead=new Node(-1);
//     Node* zeroTail=zerohead;
//     Node* oneHead=new Node(-1);
//     Node* oneTail=oneHead;
//     Node* twoHead=new Node(-1);
//     Node* twoTail=twoHead;
//     while(head!=NULL){
//         if(head->data==0){
//             Node* temp=new Node(0);
//             zeroTail->next=temp;
//             zeroTail=temp;
//         }
//         else if(head->data==1){
//             Node* temp=new Node(1);
//             oneTail->next=temp;
//             oneTail=temp;
//         }
//         else if(head->data==2){
//             Node* temp=new Node(2);
//             twoTail->next=temp;
//             twoTail=temp;
//         }
//         head=head->next;
//     }
//     zerohead=zerohead->next;
//     zeroTail->next=oneHead->next;
//     oneTail->next=twoHead->next;
//     return zerohead;
// }
// int main(){
//     Node* head=new Node(0);
//     insertAtHeadNode(head,1);
//     insertAtHeadNode(head,2);
//     insertAtHeadNode(head,0);
//     insertAtHeadNode(head,0);
//     insertAtHeadNode(head,1);
//     insertAtHeadNode(head,2);
//     Node* a=sortList(head);
//     print(a);
// }