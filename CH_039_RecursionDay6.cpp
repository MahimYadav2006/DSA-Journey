#include<bits\stdc++.h>
using namespace std;
int parti(int *arr,int start,int end){
    // int mid=start+(end-start)/2;
    int key=arr[start];
    int count=0;
    int j=start+1;
    while(j<=end){
        if(arr[j]<=key){
            count++;
        }
        j++;
    }
    int pivotIndex=start+count;
    // cout<<pivotIndex<<endl;
    swap(arr[start],arr[pivotIndex]);
    // Satisfying the condition
    int i=start;
    j=end;
    while(i<pivotIndex && j>pivotIndex){
        if(arr[i]<arr[pivotIndex]){
            i++;
        }
        else if(arr[j]>arr[pivotIndex]){
            j--;
        }
        else{
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;

}
void quickSort(int *arr,int start,int end){
    if(start>=end){
        return;
    }
    else{
        int p=parti(arr,start,end);
        quickSort(arr,start,p-1);
        quickSort(arr,p+1,end);
    }
}
int main(){
    int arr[10]={8,9,7,7,7,5,1,7,2,8};
    int n=10;
    quickSort(arr,0,n-1);
    // int arr[6]={9,10,4,6,12,177};
    // int n=6;
    // parti(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}