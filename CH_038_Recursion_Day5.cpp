#include<iostream>
#include<vector>
using namespace std;
void print(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void merge(int *arr,int start,int end){
    int mid=start+(end-start)/2;
    int len1=mid-start+1;
    int len2=end-mid;

    int *leftArray=new int[len1];
    int *rightArray=new int[len2];

    int originalIndex=start;
    for(int i=0;i<len1;i++){
        leftArray[i]=arr[originalIndex++];
    }
    originalIndex=mid+1;
    for(int i=0;i<len2;i++){
        rightArray[i]=arr[originalIndex++];
    }
    originalIndex=start;
    int i=0;
    int j=0;
    while(i<len1 && j<len2){
        if(leftArray[i]>rightArray[j]){
            arr[originalIndex++]=rightArray[j++];
            // j++;
        }
        else{
            arr[originalIndex++]=leftArray[i++];
            // i++;
        }
    }
    while(i<len1){
        arr[originalIndex++]=leftArray[i++];
        // i++;
    }
    while(j<len2){
        arr[originalIndex++]=rightArray[j++];
        // j++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort1(int *arr,int start,int end){
    if(start>=end){
        return;
    }
    else{
        int mid=start+(end-start)/2;
        // Sorting the left portion
        mergeSort1(arr,start,mid);

        // Sorting the right portion
        mergeSort1(arr,mid+1,end);

        // Merge two sorted arrays
        merge(arr,start,end);
    }
}


int main(){
    int arr[10]={10,9,8,7,125,5,5,4,3,2};
    // vector<int>arr;
    int n=10;
    // for(int i=0;i<n;i++){
    //     int j;
    //     cin>>j;
    //     arr.push_back(j);
    // }
    // vector<int>k;
    mergeSort1(arr,0,n-1);
    print(arr,n);
}

