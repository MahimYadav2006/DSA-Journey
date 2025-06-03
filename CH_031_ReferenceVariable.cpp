#include<iostream>
using namespace std;

int &update2(int n){
    int x=n;
    x++;
    int &ans=x;
    return ans;
}
void update1(int &n){
    n++;
}
int main(){

    /*
    int i=5;
    int &j=i;
    cout<<i<<endl;
    cout<<++i<<endl;
    cout<<++j<<endl;
    */

/*
   int n=5;
   cout<<"Before "<<n<<endl;
   update1(n);
   cout<<"After "<<n<<endl;
*/

    // int n=5;
    // cout<<update2(5)<<endl;
    // cout<<n<<endl;

    // // // Dynamic memory Allocation // // //
    int n;
    cin>>n;
    int *arri = new int[n];
    for(int i=0;i<n;i++){
        cin>>arri[i];
    }
    for(int i=0;i<n;i++){
        cout<<arri[i]<<" ";
    }


}