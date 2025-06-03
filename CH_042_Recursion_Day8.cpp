#include<iostream>
#include<bits\stdc++.h>
using namespace std;
void printVector(vector<string>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

void solve(string digits,string output,int index,vector<string>&ans,string mapping[]){
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }
    int number=digits[index]-'0';
    string value=mapping[number];
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digits,output,index+1,ans,mapping);
        output.pop_back();
    }
}
int main(){
    string digits;
    cin>>digits;
    vector<string>ans;
    // if(digits.empty()){
    //     return ans;
    // }
    string output="";
    string mapping[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int index=0;
    solve(digits,output,index,ans,mapping);
    printVector(ans);
}