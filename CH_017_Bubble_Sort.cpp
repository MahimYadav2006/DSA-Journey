// Optimised Bubble Sort code
#include<iostream>
using namespace std;
int main(){
    int arr[]={2,3,1,4,6,3,6,4,6,8,87,887,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        bool is_swapped=false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                is_swapped=true;
            }
        }
        if(is_swapped==false){
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}