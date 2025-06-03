#include<iostream>
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
void insertAtHeadNode(Node* &head,int d){
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
// Node* traverse(Node *head,int k){
//     Node* temp=head;
//     for(int i=1;i<=k-1;i++){
//         temp=temp->next;
//     }
//     return temp;
// }
int size(Node* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
// void printArray
void reverse(int* arr,int l,int k){
    int times=l/k;
    for(int i=0;i<times;i++){
        int z=i*k;
        int y=(i+1)*k-1;
        while(z<=y){
            swap(arr[z],arr[y]);
            z++;
            y--;
        }
    }
}
// // // // Approach 1 // // // //

// Node * kReverse(Node* head, int k){
//     int l=size(head);
//     int *arr=new int[l];
//     Node* temp=head;
//     int count=0;
//     while(temp!=NULL){
//         arr[count]=temp->data;
//         count++;
//         temp=temp->next;
//     }
//     reverse(arr,l,k);
//     temp=head;
//     int cnt=0;
//     while(temp!=NULL){
//         temp->data=arr[cnt];
//         cnt++;
//         temp=temp->next;
//     }
//     delete temp;
//     delete arr;
//     return head;
// }


// // // // Approach 2 // // // //
Node * kReverse(Node* head,int k){
    // Base case
    if(head==NULL){
        return head;
    }
    // 1 kaam jo khud karna hai
    Node* prev=NULL;
    Node* curr=head;
    int cnt=0;
    Node* xyz=NULL;
    while(curr!=NULL && cnt<k){
        xyz=curr->next;
        curr->next=prev;
        prev=curr;
        curr=xyz;
        cnt++;
    }
    if(xyz!=NULL){
        head->next=kReverse(xyz,k);
    }
    return prev;
    delete prev;
    delete curr;
    delete xyz;
    delete head;
}


bool isCircular(Node* head){
    unordered_map<Node* , bool>mp;
    if(head==NULL){
        return true;
    }
    else if(head->next==NULL){
        return false;
    }
	else if(head->next==head){
		return true;
	}
    Node* temp=head->next;
	while(temp!=NULL && temp!=head){
        if(mp[temp]==true){
            delete temp;
            delete head;
            return true;
        }
        else{
            mp[temp]=true;
        }
		temp=temp->next;
	}
	if(temp==NULL){
        delete temp;
        delete head;
		return false;
	}
	else if(temp==head){
        delete temp;
        delete head;
		return true;
	}

}
int main(){
    // Node * head=new Node(5);
    // insertAtHeadNode(head,7);
    // insertAtHeadNode(head,79);
    // insertAtHeadNode(head,78);
    // // Node * a=traverse(head,2);
    // print(head);
    
    // Node * a =kReverse(head,2);
    // print(a);


    // // Que 2 // // Is Circular linked list
    Node * head=new Node(1);
    Node * temp=head;
    insertAtHeadNode(head,8);
    insertAtHeadNode(head,3);
    insertAtHeadNode(head,4);
    insertAtHeadNode(head,5);
    insertAtHeadNode(head,2);
    insertAtHeadNode(head,1);
    temp->next=head;
    bool i=isCircular(head);
    cout<<i<<endl;
}