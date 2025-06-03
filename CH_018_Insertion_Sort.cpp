#include<iostream>
using namespace std;
int main(){
    int arr[10]={2,3,1,4,5,8,6,7,10,9};
    for(int i=1;i<10;i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}