#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

// Que 1 - > next smaller element // 


// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//     stack<int> st;
//     st.push(-1);
//     vector<int>ans(n);
//     for(int i=n-1;i>=0;i--){
//         int curr=arr[i];
//         while(st.top()>=curr){
//             st.pop();
//         }
//         ans[i]=st.top();
//         st.push(curr);
//     }
//     // reverse(ans.begin(),ans.end());
//     return ans;
// }


// // Que 2 -> Largest Rectangle in a Histogram //


    // vector<int> nextLargerElement(vector<int> &arr, int n)
    // {
    //     stack<int> st;
    //     st.push(INT_MAX);
    //     vector<int>ans(n);
    //     for(int i=n-1;i>=0;i--){
    //         int curr=arr[i];
    //         int toComp;
    //             if(st.top()!=INT_MAX){
    //                 toComp=arr[st.top()];
    //             }
    //             else{
    //                 toComp=INT_MAX;
    //             }
    //         while(toComp<=curr){
    //             st.pop();
    //             if(st.top()!=INT_MAX){
    //                 toComp=arr[st.top()];
    //             }
    //             else{
    //                 toComp=INT_MAX;
    //             }
    //         }
    //         // ans[i]=st.top();
    //         ans[i]=(st.top()==INT_MAX)?-1:st.top();
    //         st.push(i);
    //     }
    //     // reverse(ans.begin(),ans.end());
    //     return ans;
    // }



    // vector<int> prevLargerElement(vector<int> &arr, int n)
    // {
    //     stack<int> st;
    //     st.push(INT_MAX);
    //     vector<int>ans(n);
    //     for(int i=0;i<n;i++){
    //         int curr=arr[i];
    //         int toComp;
    //             if(st.top()!=INT_MAX){
    //                 toComp=arr[st.top()];
    //             }
    //             else{
    //                 toComp=INT_MAX;
    //             }
    //         while(toComp<=curr){
    //             st.pop();
    //             if(st.top()!=INT_MAX){
    //                 toComp=arr[st.top()];
    //             }
    //             else{
    //                 toComp=INT_MAX;
    //             }
    //         }
    //         // ans[i]=st.top();
    //         ans[i]=(st.top()==INT_MAX)?-1:st.top();
    //         st.push(i);
    //     }
    //     // reverse(ans.begin(),ans.end());
    //     return ans;
    // }

class Solution {
public:
    vector<int> rightSmallerElement(vector<int> &arr, int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            int toComp;
                if(st.top()!=-1){
                    toComp=arr[st.top()];
                }
                else{
                    toComp=-1;
                }
            while(toComp>=curr){
                st.pop();
                if(st.top()!=-1){
                    toComp=arr[st.top()];
                }
                else{
                    toComp=-1;
                }
            }
            // ans[i]=st.top();
            ans[i]=(st.top()==-1)?n:st.top();
            st.push(i);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<int> leftSmallerElement(vector<int> &arr, int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            int toComp;
                if(st.top()!=-1){
                    toComp=arr[st.top()];
                }
                else{
                    toComp=-1;
                }
            while(toComp>=curr){
                st.pop();
                if(st.top()!=-1){
                    toComp=arr[st.top()];
                }
                else{
                    toComp=-1;
                }
            }
            // ans[i]=st.top();
            ans[i]=st.top();
            st.push(i);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>right=rightSmallerElement(heights,n);
        vector<int>left=leftSmallerElement(heights,n);
        // vector<int>ans(n);
        // for(int i=0;i<n;i++){
        //     ans[i]=heights[i]*(right[i]-left[i]-1);
        // }
        // int max=INT_MIN;
        // for(int i: ans){
        //     if(i>max){
        //         max=i;
        //     }
        // }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int area=heights[i]*(right[i]-left[i]-1);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
int main(){
    vector<int>v={2,1,5,6,2,3};
    vector<int>ans=rightSmallerElement(v,6);
    vector<int>ans2=leftSmallerElement(v,6);
    cout<<endl;
        for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i: ans2){
        cout<<i<<" ";
    }
    cout<<endl;
}