#include<bits\stdc++.h>
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
void insertAtHeadNode(int data,Node* &head){
    Node* temp=new Node(data);
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
bool isPalindrome(Node* head){
    if(head==NULL){
        return false;
    }
    else if(head->next==NULL){
        return true;
    }
    else if(head->next->next==NULL && head->next->data==head->data){
        return true;
    }
    else if(head->next->next==NULL && head->next->data!=head->data){
        return false;
    }
    else if(head->next->next->next==NULL && head->data==head->next->next->data){
        return true;
    }
    else if(head->next->next->next==NULL && head->data!=head->next->next->data){
        return false;
    }
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    };
    int mid=count/2;
    int z=1;
    temp=head;
    Node* preserve=NULL;
    // cout<<count<<endl;
    if(count%2==0){
        while(z<count/2){
            z++;
            temp=temp->next;
        }
        preserve=temp;
        temp=temp->next;
    }
    else{
        while(z<=count/2){
            z++;
            if(temp->next!=NULL){
                temp=temp->next;
            }
        }
        preserve=temp;
        temp=temp->next;
    }
    // cout<<"HI"<<endl;
    Node* curr=temp;
    Node* prev=NULL;
    while(curr!=NULL){
        Node* xyz=curr->next;
        curr->next=prev;
        prev=curr;
        curr=xyz;
    }
    preserve->next=prev;
    // cout<<preserve->next->data;
    // cout<<"HI"<<endl;
    
    // print(head);

    // checking palindrome or not  // //
    Node* kite=head;
    int mix=count/2;
    for(int i=0;i<mix;i++){
        kite=kite->next;
    }
    if(count%2!=0){
        kite=kite->next;
    }
    int cnt=0;
    while(kite!=NULL && cnt<mix){
        if(head->data!=kite->data){
            return false;
        }
        cnt++;
        head=head->next;
        kite=kite->next;
    }
    return true;

}
int main(){
    Node* head=new Node(1);
    insertAtHeadNode(2,head);
    insertAtHeadNode(0,head);
    insertAtHeadNode(1,head);
    insertAtHeadNode(0,head);
    insertAtHeadNode(1,head);
    // print(head);
    cout<<isPalindrome(head);
}