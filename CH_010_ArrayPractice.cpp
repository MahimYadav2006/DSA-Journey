#include <iostream>
using namespace std;
void sortOne(int arr[],int size){
    int i=0,j=size-1;
    while(i<j){
        if(arr[i]==0){
            i++;
        }
        else if(arr[j]==1){
            j--;
        }
        else if(arr[i]==1 && arr[j]==0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }

    }
}
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){

    // // Swapping the alternate value of an array
    // int arr[9]={1,2,3,4,5,6,7,8,9};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // for(int i=0;i<n;i+=2){
    //     if(i+1<n){
    //         int temp=arr[i];
    //         arr[i]=arr[i+1];
    //         arr[i+1]=temp;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

//     //Finding the unique element of the array
//     int arr[7]={1,1,2,2,3,3,4};
//     int ans=0;
//     for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
//         ans=ans^arr[i];
//     }
//     cout<<ans<<endl;

    // Sort 0,1 using two pointers approach
    int arr[8]={0,1,0,1,1,0,0,1};
    sortOne(arr,8);
    printArray(arr,8);
    
}