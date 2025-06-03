#include<iostream>
using namespace std;
int getLength(char s[]){
    int count=0;
    while(s[count]!='\0'){
        count++;
    }
    return count;
}
void reverseArray(char name[]){
    int n=getLength(name);
    int s=0;
    int e=n-1;
    while(s<=e){
        swap(name[s],name[e]);
        s++;
        e--;
    }
    cout<<name<<endl;
}
int main(){
    char name[20];
    cin>>name;
    cout<<name<<endl;
    cout<<getLength(name)<<endl;
    reverseArray(name);
}