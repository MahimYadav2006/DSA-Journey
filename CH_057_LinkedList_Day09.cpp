#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* arb;
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->arb=NULL;
    }
};
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void insertAtTailNode(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}


// // // // Approach 1 // // // //
    // Node *copyList(Node *head)
    // {
    //     Node* cloneHead=NULL;
    //     Node* cloneTail=NULL;
    //     Node* temp=head;
    //     while(temp!=NULL){
    //         insertAtTailNode(cloneHead,cloneTail,temp->data);
    //         temp=temp->next;
    //     }
    //     // Creating a map
    //     unordered_map<Node*,Node*>oldToNewNode;
    //     Node* originalNode=head;
    //     Node* cloneNode=cloneHead;
    //     while(originalNode !=NULL && cloneNode!=NULL){
    //         oldToNewNode[originalNode]=cloneNode;
    //         originalNode=originalNode->next;
    //         cloneNode=cloneNode->next;
    //     }
    //     originalNode=head;
    //     cloneNode=cloneHead;
    //     while(originalNode!=NULL){
    //         cloneNode->arb=oldToNewNode[originalNode->arb];
    //         originalNode=originalNode->next;
    //         cloneNode=cloneNode->next;
    //     }
    //     return cloneHead;
    // }

    

// // // // Approach 2 // // // //


    Node *copyList(Node *head)
    {
        Node* clone=NULL;
        Node* temp=head;
        Node* cloneHead;
        while(temp!=NULL){
            Node* xyz=new Node(temp->data);
            if(clone==NULL){
                clone=xyz;
                cloneHead=clone;
                temp=temp->next;
            }
            else{
                clone->next=xyz;
                clone=xyz;
                temp=temp->next;
            }
        }
        // print(cloneHead);
        Node* copy=cloneHead;
        temp=head;
        while(temp!=NULL || copy!=NULL){
            Node* abc=temp->next;
            temp->next=copy;
            Node* cpyabc=copy->next;
            copy->next=abc;
            temp=abc;
            copy=cpyabc;
        }
        // print(head);
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                if(temp->arb!=NULL){
                    temp->next->arb=temp->arb->next;
                }
            }
            temp=temp->next;
            // cout<<"Hello "<<" ";
            if(temp->next!=NULL){
                temp=temp->next;
            }
            else{
                break;
            }
        }
        // cout<<"Hi"<<endl;
        copy=cloneHead;
        temp=head;
        // while( copy!=NULL){
        //     Node* abc=copy->next;
        //     if(abc!=NULL && abc->next!=NULL){
        //         copy->next=abc->next;
        //     }
        //     // copy->next=copy->next->next;
        //     // if(copy->next!=NULL){
        //     //     copy->next=copy->next;
        //     // }
        //     // else{
        //     //     break;
        //     // }
        //     if(copy->next!=NULL){
        //         copy=copy->next;
        //     }
        //     else{
        //         break;
        //     }
        // }
        while(copy!=NULL && temp!=NULL){
            Node* abc=temp->next;
            if(abc!=NULL ){
                temp->next=abc->next;
                temp=abc->next;
            }
            else{
                break;
            }
            if(temp!=NULL ){
                abc->next=temp->next;
            }
            else{
                // temp=temp->next;
                break;
            }
            // temp=temp->next;
        }
        // print(head);
        // print(cloneHead);
        return cloneHead;
    }
int main(){
    Node* tail=new Node(1);
    Node* head=tail;
    Node* one=tail;
    insertAtTailNode(tail,2);
    Node* two=tail;
    insertAtTailNode(tail,3);
    Node* three=tail;
    insertAtTailNode(tail,4);
    Node* four=tail;
    insertAtTailNode(tail,5);
    Node* five=tail;
    one->arb=three;
    two->arb=one;
    three->arb=five;
    four->arb=three;
    five->arb=two;
    print(head);
    copyList(head);
}