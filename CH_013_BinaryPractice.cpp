#include <iostream>
using namespace std;
int floorSqrt(long long int n)
{
    long long int start=0;
    long long int end=n;
    long long int mid=start+(end-start)/2;
    while(start<=end){
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid>n && (mid-1)*(mid-1)<n){
            return mid-1;
        }
        else if(mid*mid>n){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
}
double floatsqrt(int n,int accuracy,int floorsq){
    double factor=1;
    double ans=floorsq;
    for(int i=0;i<accuracy;i++){
        factor=factor/10;
        for(double j=floorsq;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;

}
// int pivotIndex(int arr[],int n){
//     int start=0;
//     int end=n-1;
//     int mid=start+(end-start)/2;
//     while(start<end){
//         if(arr[mid]>=arr[0]){
//             start=mid+1;
//         }
//         else{
//             end=mid;
//         }
//         mid=start+(end-start)/2;
//     }
//     return start;
// }
int main(){
    // int arr[5]={8,10,17,1,3};
    // cout<<pivotIndex(arr,5)<<endl;
    cout<<floatsqrt(2,8,floorSqrt(2))<<endl;
}