#include<iostream>
#include<queue>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        arr[0]=-1;
        size=0;
    }
    void addElement(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1 ){
            int parent=index/2;
            if(arr[parent] <= arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void deleteNode(){
        if(size==0){
            cout<<"UnderFlow Condition"<<endl;
            return;
        }
        // First node me last node daalna
        arr[1]=arr[size];
        // Last node ko delete krna
        size--;
        // Trvaerse root to childs
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{
                // Our heap is ok
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }
};
void heapify(int *arr,int n,int i){   // For 1 based indexing 
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[left]>arr[largest]){
        swap(largest,left);
    }
    if(right<=n && arr[right]>arr[largest]){
        swap(largest,right);
    }
    // Check whether the index i and largets are same or not
    if(largest!=i){
        swap(arr[largest],arr[i]);
        // Check whether the largest is at its correct position or not
        heapify(arr,n,largest);
    }
}

    void heapify(vector<int>& arr,int index,int n){  // For 0 based indexing 
        int left=2*index+1;
        int right=2*index+2;
        int largest=index;
        if(left< n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<n && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=index){
            swap(arr[largest],arr[index]);
            heapify(arr,largest,n);
        }
    }
void heapSort(int *arr,int n){
    while(n>1){
        swap(arr[n],arr[1]);
        n--;
        // Taking root node to correct pos
        heapify(arr,n,1);
    }
}
int main(){


    // Heap h;
    // // h.addElement(50);
    // // h.addElement(55);
    // // h.addElement(53);
    // // h.addElement(52);
    // // h.addElement(54);
    // // h.print();
    // // cout<<endl;
    // // h.deleteNode();
    // // h.print();

    // h.addElement(55);
    // h.addElement(60);
    // h.addElement(45);
    // h.addElement(12);
    // h.addElement(78);
    // h.addElement(122);
    // h.deleteNode();
    // h.print();
    // cout<<endl;


    // // int arr[]={-1,54,53,55,52,50};
    // int arr[]={-1,520,420,320,220,120};
    // int n=5;

    // // // For 1 based indexing // // //

    // for(int i=n/2;i>0;i--){
    //     heapify(arr,n,i);
    // }

    // // // For 0 based indexing  /// // //

    // for(int i=n/2-1;i>=0;i--){
    //     heapify(arr,i,n);
    // }



    // for(auto i: arr){
    //     cout<<i<<" ";
    // }cout<<endl;
    // heapSort(arr,n);
    // for(auto i: arr){
    //     cout<<i<<" ";
    // }cout<<endl;

    priority_queue<int> pq;   // It is by default max heap
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3); 
    cout<<"Element at top "<<pq.top()<<endl;   // Jarur top pe maximum element pada hoga
    pq.pop();
    cout<<"Element at top "<<pq.top()<<endl;   // Ab dekhenge to top pe second max element pada hoga

    // For min heap
    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(1);
    cout<<"Element at top "<<minHeap.top()<<endl;   // Jarur top pe minimum element pada hoga
    minHeap.pop();
    cout<<"Element at top "<<minHeap.top()<<endl;    
}


// Just for keeping it safe
    long long minCost(long long arr[], long long n) {
        priority_queue<long long ,vector<long long>,greater<long long>> pq;
        for(auto i: arr){
            pq.push(i);
        }
        long long  ans=0;
        while(pq.size()>1){
            long long sum=0;
            sum+=pq.top();
            pq.pop();
            sum+=pq.top();
            pq.pop();
            pq.push(sum);
            ans+=sum;
        }
        return ans;
    }

// // Nice approach -> keep it safe
class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>c;
        c.push_back(-1); for(int i=0; i<n; i++){
            c.push_back(a[i]);
        }
        for(int i=0; i<m; i++){
            c.push_back(b[i]);
            int index = c.size()-1;
            int parent = index/2 ;
            while(index > 1 && c[parent]<c[index]){
                swap(c[parent],c[index]);
                index = parent; parent = index/2;
            }
        }
      
        c.erase(c.begin());
        return c;
    }
};