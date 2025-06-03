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
bool isLooped(Node* head){
	if(head==NULL){
		return true;
	}
	else if(head->next==NULL){
		return false;
	}
	map<int,bool>m;
	Node* temp=head->next;
	while(temp!=NULL){
		int d=temp->data;
		if(m[d]==true){
			return true;
		}
		m[d]=true;
		temp=temp->next;
	}
	return false;
}
// // Floyds Cycle Algorithm // //
Node* floydsCycle(Node* head){
    if(head==NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head;
    while((slow!=NULL) && (fast!=NULL || fast->next!=NULL)){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            // delete slow;
            // delete fast;
            // delete head;
            return slow;
        }
    }
    // delete slow;
    // delete fast;
    // delete head;
    return NULL;
}
// // Finding the point of the beginning of the loop // //
Node* getStartingNode(Node* head){
    if(head==NULL){
        return head;
    }
    Node* fast=floydsCycle(head);
    Node* slow=head;
    while(slow!=fast && slow!=NULL && fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    if(slow==fast){
        return slow;
    }
    else{
        return NULL;
    }
}
Node *removeLoop(Node *head)
{
    Node * todo=getStartingNode(head);
    Node* temp=todo;
    while(temp->next!=todo){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    delete head;
}
int main(){
    Node * head=new Node(55);
    Node * temp=head;
    insertAtHeadNode(head,4);
    insertAtHeadNode(head,15);
    insertAtHeadNode(head,12);
    Node * temp2=head;
    insertAtHeadNode(head,23);
    temp->next=temp2;
    // cout<<isLooped(head)<<endl;
    // cout<<floydsCycle(head)->data<<endl;
    // Node* a=get1lessStartingNode(head);
    Node* b=removeLoop(head);
    print(b);
    Node * z=floydsCycle(b);
    if(z==NULL){
        cout<<"No looping";
    }
    // delete a;
    // delete b;
    // delete temp;
    // delete temp2;
    // delete head;

}