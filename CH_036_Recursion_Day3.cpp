#include<iostream>
using namespace std;
// bool is_Sorted(int arr[],int size,int i=0){
//     if(i==size-1){
//         return true;
//     }
//     else if(arr[i]<=arr[i+1]){
//         i++;
//         // cout<<i<<" ";
//         return is_Sorted(arr,10,i);
//     }
//     else{
//         return false;
//     }
// }


bool is_Sorted(int *arr,int size){
    // cout<<size<<endl;
    if(size==1 || size==0){
        return true;
    }
    else{
        if(arr[0]>arr[1]){
            return false;
        }
        else{
            size--;
            return is_Sorted(arr+1,size);
        }
    }
}
int sum(int *arr,int size){
    if(size==0){
        return 0;
    }
    else if(size==1){
        return arr[0];
    }
    else{
        int remaining_part=sum(arr+1,size-1);
        int ans=arr[0]+remaining_part;
        return ans;
    }
}
void print(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}
bool isPresent(int *arr,int size,int key){
    // Just for sake of understanding
    print(arr,size);
    if(size==0){
        return false;
    }
    else{
        if(arr[0]==key){
            return true;
        }
        else{
            return isPresent(arr+1,size-1,key);
        }
    }
}
bool recursive_Binary_Search(int *arr,int key,int start,int end){
    // int size=sizeof(arr)/sizeof(arr[0]);
    int mid=start+(end-start)/2;
    if(end<start){
        return false;
    }
    if(arr[mid]==key){
        return true;
    }
    else if(arr[mid]>key){
        return recursive_Binary_Search(arr,key,start,mid-1);
    }
    else{
        return recursive_Binary_Search(arr,key,mid+1,end);
    }
}
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,12,15};
    // cout<<is_Sorted(arr,10)<<endl;
    // cout<<sum(arr,10)<<endl;
    // cout<<isPresent(arr,10,12)<<endl;
    // cout<<recursive_Binary_Search(arr,125,0,9);
}