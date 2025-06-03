#include<iostream>
#include<vector>
using namespace std;
int main(){
    // int num=5;
    // cout<<"Value of num is: "<<num<<endl;
    // int *ptr=&num;
    // cout<<"Address of num is "<<ptr<<endl;
    // cout<<"Value at ptr address is "<<*ptr<<endl;
    // cout<<"Size of int num is "<<sizeof(num)<<endl;
    // cout<<"Size of pointer ptr is "<<sizeof(&num)<<endl;
    // // (*ptr)++;
    // // cout<<num<<endl;

    // int *q=ptr;
    // cout<<*q<<endl;
    // cout<<(*q)++<<endl;
    // cout<<num<<endl;
    // cout<<q<<endl;
    // q=q+1;
    // cout<<q<<endl;
    // // cout<<*q;
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    // int *p=&arr[0];
    for(auto it=arr.begin();it!=arr.end();++it){
        cout<<*it<<endl;
    }


}