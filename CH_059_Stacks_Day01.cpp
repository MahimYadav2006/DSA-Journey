#include<iostream>
// #include<stack>
#include<climits>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class stack{
    public:
    int data;
    stack* next;
    stack(int data){
        this->data=data;
        this->next=NULL;
    }
    void push(stack* &s,int data){
        stack* temp=new stack(data);
        temp->next=s;
        s=temp;
    }
    void pop(stack* &s){
        stack* temp=s;
        s=s->next;
        delete temp;
    }
    int top(stack* &s){
        if(s==NULL){
            return INT_MIN;
        }
        else{
            return s->data;
        }
    }
    bool empty(stack* &s){
        if(s==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    // // Stack using STL // // 

    // stack<int>s;
    // s.push(2);
    // s.push(3);
    // s.pop();
    // s.pop();
    // cout<<s.top()<<endl;
    // s.pop();
    // if(s.empty()){
    //     cout<<"Stack is empty"<<endl;
    // }
    // else{
    //     cout<<"Stack S is not empty."<<endl;
    // }

    // // Stack using stack class // //
    stack* s=new stack(4);
    s->push(s,3);
    s->push(s,5);                         
    s->push(s,1);
    s->pop(s);
    cout<<s->top(s)<<endl;                                  
    cout<<s->empty(s)<<endl;



// Question //


// #include <bits/stdc++.h> 
// class TwoStack {
//            int *arr;
//            int top1;
//            int top2;
//            int size;
// public:

//     // Initialize TwoStack.
//     TwoStack(int s) {
//         // Write your code here.
//         this-> size =s;
//         top1 = -1;
//         top2 = s;
//         arr=new int[s];
//     }
    
//     // Push in stack 1.
//     void push1(int num) {
//         // Write your code here.
//         if(top2-top1 > 1){
//             top1++;
//             arr[top1]=num;
//         }
       
//     }

//     // Push in stack 2.
//     void push2(int num) {
//         // Write your code here.
//         if(top2-top1>1){
//             top2--;
//             arr[top2]=num;
//         }
       

//     }

//     // Pop from stack 1 and return popped element.
//     int pop1() {
//         // Write your code here.
//        if(top1 >=0){
//             int ans = arr[top1];
//             top1--;
//             return ans;
//         }
//         else{
//             return -1;
//         }
//     }

//     // Pop from stack 2 and return popped element.
//     int pop2() {
//         // Write your code here.
//         if( top2 < size){
//             int ans = arr[top2];
//             top2++;
//             return ans;
//         }
//         else{
//             return -1;
//         }
//     }
// };

}