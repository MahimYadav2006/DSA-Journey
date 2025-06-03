#include <iostream>
using namespace std;
void update(int arr[],int size){
    arr[0]=120;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
bool search(int arr[],int size,int n){
    for(int i=0;i<size;i++){
        if(arr[i]==n){
            return true;
        }
    }
    return false;
}
void reversearray(int a[],int n){
    int start=0;
    int end=n-1;
    while(start<=end){
        swap(a[start],a[end]);
        start++;
        end--;
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    // // Calculating the max and min value in an array
    // int a[]={2,3,4,5,6,6,34,5};
    // int max=a[0];
    // int min=a[0];
    // for(int i=0;i<sizeof(a)/sizeof(int);i++){
    //     if(max<a[i]){
    //         max=a[i];
    //     }
    //     if(min>a[i]){
    //         min=a[i];
    //     }
    // }
    // cout<<max<<endl;
    // cout<<min<<endl;

    // Array scope
    // int arr[]={1,2,3,45,5};
    // int size=sizeof(arr)/sizeof(arr[0]);
    // update(arr,size);
    // cout<<endl;
    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // } 

    // // Linear Search
    // int arr[10]={1,2,3,4,5,6,7,8,9,10};
    // cout<<(search(arr,10,7))<<endl;
    // cout<<(search(arr,10,11))<<endl;

    // Reversing an array
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[5]={3,4,2,5,2};
    reversearray(a,10);
    reversearray(b,5);
    printArray(a,10);
    printArray(b,5);
}