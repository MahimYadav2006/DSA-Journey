#include<bits\stdc++.h>
using namespace std;
string reverse(string s,int i,int last){
    int size=s.length();
    int mid=size/2;
    if(i==mid){
        return s;
    }
    else{
        swap(s[i],s[last]);
        last--;
        i++;
        return reverse(s,i,last);
    }
}
string binary(long long n){
    string s;
    while(n!=0){
        s+=to_string(n%2);
        n=n/2;
    }
    return s;
}
int power(int a,int b){
    if(b==0){
        return 1;
    }
    else{
        if(b%2==0){
            return power(a,b/2)*power(a,b/2);
        }
        else{
            return a*power(a,b/2)*power(a,b/2);
        }
    }
}
bool is_palindrome(long long int n,int i,int j){
    string s=binary(n);
    // int z=s.length()-1;
    if(i>j){
        return true;
    }
    else{
        if(s[i]!=s[j]){
            return false;
        }
        else{
            i++;
            j--;
            return is_palindrome(n,i,j);
        }
    }
}
void sortArray(int *arr,int n){
    if(n==0 || n==1){
        return;
    }
    else{
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        n--;
        sortArray(arr,n);
    }
}
int main(){
    // string s;
    // cin>>s;
    // cout<<reverse(s,0,s.length()-1)<<endl;
    // cout<<is_palindrome(s,0,s.length()-1)<<endl;
    long long int n=15;
    // string binary =bitset<2>(n).to_string();
    // cout<<binary(n)<<endl;
    // cout<<power(2,5)<<endl;
    // cout<<power(3,6);
    int arr[10]={1,4,2,6,5,3,9,7,8,10};
    sortArray(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<' ';
    }
}