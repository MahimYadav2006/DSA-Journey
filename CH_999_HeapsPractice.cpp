#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    vector<int> arr;
    int size;
    Heap(int maxSize){
        size = 0;
        arr.resize(maxSize+1);
        arr[0] = 1;
    }
    void insertInHeap(int val){
        size++;
        arr[size] = val;
        int index = size;
        while(index > 1){
            int parent = index/2;
            if(arr[parent] <= arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else break;
        }
    }
    void printHeap(){
        for(int i=1;i<=size;i++) cout<<arr[i]<<" ";
    }
    void deleteElement(){
        swap(arr[1],arr[size]);
        size--;
        int index = 1;
        while(index <= size){
            int lc = 2*index;
            int rc = 2*index+1;
            int largest = index;
            if(lc <= size && arr[lc] > arr[largest]) largest = lc;
            if(rc <= size && arr[rc] > arr[largest]) largest = rc;
            if(largest == index) break;
            swap(arr[largest],arr[index]);
            index = largest;
        }
    }
};
class MinHeap{
    public:
    vector<int> arr;
    int size;
    MinHeap(int maxSize){
        size = 0;
        arr.resize(maxSize+1);
        arr[0] = 1;
    }
    void insertInHeap(int val){
        size++;
        arr[size] = val;
        int index = size;
        while(index > 1){
            int parent = index/2;
            if(arr[parent] >= arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else break;
        }
    }
    void printHeap(){
        for(int i=1;i<=size;i++) cout<<arr[i]<<" ";
    }
    void deleteElement(){
        swap(arr[1],arr[size]);
        size--;
        int index = 1;
        while(index <= size){
            int lc = 2*index;
            int rc = 2*index+1;
            int smallest = index;
            if(lc <= size && arr[lc] < arr[smallest]) smallest = lc;
            if(rc <= size && arr[rc] < arr[smallest]) smallest = rc;
            if(smallest == index) break;
            swap(arr[smallest],arr[index]);
            index = smallest;
        }
    }
};

void heapify(int *arr,int n,int index){ // Sift Down Heapify Algo
    while(index < n){
        int largest = index;
        int lc = 2*index+1;
        int rc = 2*index+2;
        if(lc < n && arr[lc] > arr[largest]) largest = lc;
        if(rc < n && arr[rc] > arr[largest]) largest = rc;
        if(largest == index) break;
        swap(arr[largest],arr[index]);
        index = largest;
    }
}



// void heapify(int *arr,int n,int index){
//     while(index >= 0){
//         int parent = (index&1)?index/2:index/2-1;
//         if(parent <0) break;
//         if(arr[parent] < arr[index]){
//             swap(arr[parent],arr[index]);
//             index = parent;
//         }
//         else{
//             break;
//         }
//     }
// }

void buildHeap(int *arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}
void heapSort(int *arr,int n){
    buildHeap(arr,n);
    while(n > 1){
        swap(arr[n-1],arr[0]);
        n--;
        heapify(arr,n,0);
    }
}
int main(){
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    heapSort(arr,10);
    for(int i=0;i<10;i++) cout<<arr[i]<<" ";

}