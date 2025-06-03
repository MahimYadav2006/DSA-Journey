#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
int power(int n){
    // Base case
    if(n==0){
        return 1;
    }
    // Recursive relation
    else{
        return 2*power(n-1);
    }
}
void counting(int n){

    // Base case
    if(n==1){
        cout<<n<<" ";
        return;
    }

    // Recursive relation
    cout<<n<<" ";
    counting(n-1);

}
int main(){
    int n;
    cin>>n;

    // int ans=factorial(n);
    // cout<<ans<<endl;


    // cout<<power(n)<<endl;

    counting(n);

}