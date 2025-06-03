#include<iostream>
#include<stack>
#include<string>
#include<climits>
#include<vector>
using namespace std;
string reverse(string s){
    stack<char>temp;
    for(int i=0;i<s.length();i++){
        temp.push(s[i]);
    }
    string ans;
    while(!temp.empty()){
        ans.push_back(temp.top());
        temp.pop();
    }
    return ans;
}

// Add element to the bottom of a stack
void insertAtBottom(stack<int> &s,int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int x=s.top();
    s.pop();
    insertAtBottom(s,element);
    s.push(x);

}
void printStack(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void reverseStack(stack<int>&s){
    if(s.empty() || s.size()==1){
        return;
    }
    int element=s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,element);
}
void deletemid(stack<int> &s,int N, int &cnt){
   if(cnt==(N+1)/2){
      s.pop();
      return;
   }
   int x=s.top();
   s.pop();
   cnt++;
   deletemid(s,N,cnt);
   s.push(x);
}
void deleteMiddle(stack<int>&inputStack, int N){
	int cnt=0;
   deletemid(inputStack,N,cnt);
}
// bool isValidParenthesis(string s)
// {
//     stack<int>st;
//     int i=0;
//     while(i<s.length()){
//         bool condn;
//         if(!st.empty()){
//             int n=s[i]-st.top();
//             condn= n==2 || n==1;
//         }
//         else{
//             condn=true;
//         }
//         if(!condn || st.empty()){
//             st.push(s[i]);
//         }
//         else{
//             st.pop();
//         }
//         i++;
//     }
//     if(st.size()==0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

bool isValidParenthesis(string s){
    stack<char>st;
    int i=0;
    while(i<s.length()){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]=='}'){
            if(st.top()=='{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        else if(s[i]==']'){
            if(st.top()=='['){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        else{
            if(st.top()=='('){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        i++;
    }
    return st.empty();
}
void printCharStack(stack<char> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

bool findRedundantBrackets(string &s)
{   
    stack<char>st;
    bool isOp;
    bool isNormal;
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(s[i]!=')'){
            st.push(s[i]);
        }
        else{
            isOp=false;
            // isNormal=false;
            while(st.top()!='('){
                char x=st.top();
                st.pop();
                if(x=='+' || x=='-' || x=='*' || x=='/'){
                    isOp=true;
                }
                // if(x>=97 && x<=122){
                //     isNormal=true;
                // }
            }
            st.pop();
            if(isOp==false){
                return true;
            }
        }
    }
    // printCharStack(st);
    return false;
}
#include <bits/stdc++.h> 
string makeString(stack<char> st){
    string s="";
    while(!st.empty()){
        s.push_back(st.top());
        st.pop();
    }
    return s;
}
int findMinimumCost(string str) {
    stack<char>st;
    for(int i=str.length()-1;i>=0;i--){
        if(st.empty()){
            st.push(str[i]);
        }
        else if(str[i]=='{'){
            if(st.top()=='}'){
                st.pop();
            }
            else{
                st.push(str[i]);
            }
        }
        else{
            st.push(str[i]);
        }
    }
    // printCharStack(st);
    if(st.size()==0){
        return 0;
    }
    else if(st.size()==1){
        return -1;
    }
    else{
        string s=makeString(st);
        // cout<<s<<endl;
        int i=0;
        int cnt=0;
        while(i<s.length()-1){
            if(s[i]=='}' && s[i+1]=='}'){
                s[i]='{';
                cnt++;
                i+=2;
            }
            else if(s[i]=='{' && s[i+1]=='}'){
                i+=2;
            }
            else if(s[i]=='}' && s[i+1]=='{'){
                cnt+=2;
                // cout<<i<<endl;
                // cout<<s<<endl;
                s[i]='{';
                s[i+1]='}';
                // cout<<s<<endl;
                i+=2;
            }
            else{
                cnt+=1;
                s[i+1]='}';
                i+=2;
            }
        }
        // cout<<s<<endl;
        if(s[s.length()-1]=='{'){
            return -1;
        }
        if(s[s.length()-1]=='}' && s[s.length()-2]=='}'){
            return -1;
        }
        else{
            // cout<<cnt<<endl;
            return cnt;
        }
    }
}
int main(){
    // Que 1 // 

    // string s;
    // cin>>s;
    // string k=reverse(s);
    // cout<<k<<endl;

    // Que 2 //
    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // printStack(s);
    // insertAtBottom(s,45);
    // printStack(s);

    // Que 3 //   // // Reverse a Stack using recursion
    // reverseStack(s);
    // printStack(s);

    // // Delete Middle element from stack
    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // // s.push(5);
    // int n=3;
    // printStack(s);
    // deleteMiddle(s,n);
    // printStack(s);

    // Valid Parenthesis // 
    // string s="{{}}";
    // bool i=isValidParenthesis(s);
    // cout<<i<<endl;

    // Redundant Brackets //
    // string s="(a/c+(b))";
    // cout<<findRedundantBrackets(s)<<endl;

    // Find minimum cost //
    string str="{{}{}}";
    cout<<findMinimumCost(str);

}