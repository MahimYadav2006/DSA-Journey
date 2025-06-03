#include<iostream>
using namespace std;
void reachHome(int src,int dest){
    cout<<"Source is "<<src<<" and destination is "<<dest<<endl;
    // Base case
    if(src==dest){
        cout<<"Pahuch Gya"<<endl;
        return;
    }

    // Processing
    src++;

    // Recursive relation
    reachHome(src,dest);

}
int fib(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
int fibo2(int n){
    int ans1=0;
    int ans2=1;
    int ans;
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        for(int i=2;i<=n;i++){
            ans=ans1+ans2;
            ans1=ans2;
            ans2=ans;
        }
        return ans;
    }
}

// #include <bits/stdc++.h> 
// int countDistinctWays(int nStairs) {
//     if(nStairs<0){
//         return 0;
//     }
//     else if(nStairs==0){
//         return 1;
//     }
//     else{
//         return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
//     }
// }

void sayDigit(int n){
    string str[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    if(n==0){
        return;
    }
    int reqd=n%10;
    // PROCESSING PART
    n=n/10;
    // Recursive call
    sayDigit(n);
    cout<<str[reqd]<<" ";
}
int main(){

    // reachHome(1,10);

    int n;
    cin>>n;
    // cout<<fib(n)<<endl;
    // cout<<fibo2(n)<<endl;

    sayDigit(n);
}