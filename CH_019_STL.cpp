#include<iostream>
#include <array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include <map>
#include<algorithm>
using namespace std;
int main(){
    ////// Arrays


    // array<int,4>a={1,2,3,4};
    // int size=a.size();
    // for(int i=0;i<size;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"Element at 3rd index is: "<<a.at(3)<<endl;
    // cout<<"Checking if a is empty or not: "<<a.empty()<<endl;
    // cout<<"Getting the first value: "<<a.front()<<endl;
    // cout<<"Getting the last value: "<<a.back()<<endl;

    ////// Vectors
    // vector<int>v;
    // for(int i=0;i<8;i++){
    //     int z;
    //     cin>>z;
    //     v.push_back(z);
    // }
    // for(int i=0;i<8;i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<"Capacity of v is: "<<v.capacity()<<endl;
    // cout<<"Size of v is: "<<v.size()<<endl;
    // cout<<"First element is: "<<v.front()<<endl;
    // cout<<"Last element is: "<<v.back()<<endl;
    // v.pop_back();
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // v.clear();
    // cout<<"Now the capacity of v is: "<<v.capacity()<<endl;  // Capacity of v is still same
    // cout<<"Now the size of v is: "<<v.size()<<endl;          // But the size of v has decreased significantly to 0


    ////// DEQUE
    // deque<int>d;
    // d.push_back(1);
    // d.push_front(2);
    // d.push_front(90);
    // d.pop_back();
    // d.pop_front();
    // for(int i:d){
    //     cout<<i<<" ";
    // }

    // // // // LIST // // // //
    // list<int>l;
    // l.push_back(3);
    // l.push_front(2);
    // for(int i:l){
    //     cout<<i<<" ";
    // }
    // // All previous methods also apply here

    // // // // STACK // // // //
    // stack<string>s;
    // s.push("Mahim");
    // s.push("Yadav");
    // s.push("is");
    // s.push("my");
    // s.push("name");
    // cout<<s.top()<<endl;
    // s.pop();
    // cout<<s.top()<<endl;
    // cout<<"Size of s is: "<<s.size()<<endl;
    // cout<<"Checks if empty or not."<<s.empty()<<endl;


    // // /// // QUEUE // // // //
    // queue<string>q;
    // q.push("Mahim");
    // q.push("Yadav");
    // cout<<"First element: "<<q.front()<<endl;
    // q.pop();
    // cout<<"Now "<<q.front()<<endl;

    // // // // Priority Queue // // // //
    // priority_queue<int>maxi;
    // maxi.push(1);
    // maxi.push(0);
    // maxi.push(9);
    // maxi.push(78);
    // maxi.push(-4);
    // // for(int i=0;i<maxi.size();i++){      Issue is here
    // //     cout<<maxi.top()<<" ";       
    // //     maxi.pop();
    // // }
    // int n=maxi.size();
    // for(int i=0;i<n;i++){
    //     cout<<maxi.top()<<" ";
    //     maxi.pop();
    // }

    // // Min heap queue
    // priority_queue<int,vector<int>,greater<int>>mini;
    // mini.push(9);
    // mini.push(8);
    // mini.push(3);
    // mini.push(1);
    // mini.push(98);
    // mini.push(-7);
    // int k=mini.size();
    // for(int i=0;i<k;i++){
    //     cout<<mini.top()<<" ";
    //     mini.pop();
    // }
    // cout<<mini.empty();

    // // // // SET // // // //
    // set<int>s;
    // s.insert(1);
    // s.insert(0);
    // s.insert(99);
    // s.insert(-8);
    // s.insert(99);
    // for(auto i:s){
    //     cout<<i<<" ";
    // }
    // set<int>::iterator itr=s.find(-8);
    // cout<<*itr<<endl;

    // // // // MAP // // // //
    // map<int,string>m;
    // m[1]="Love";
    // m[2]="Babbar";
    // m[13]="Kumar";
    // m.insert({5,"bheem"});
    // for(auto i:m){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    // // // // ALGORITHMS // // // //
    
    


}