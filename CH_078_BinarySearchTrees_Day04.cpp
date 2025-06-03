#include<bits\stdc++.h>
using namespace std;

 // // // // Approach 1 // // // //


// void inorder(TreeNode* root, vector<int>& v){
//     if(root == NULL){
//         return ;
//     }

//     inorder(root->left, v);
//     v.push_back(root->data);
//     inorder(root->right,v);
// }


// // TreeNode* solve(int start, int end, vector<int>& ans){
// //     if(start>end){
// //         return NULL;
// //     }
// //     int mid = (start+end)/2;
// //     TreeNode* temp = new TreeNode(ans[mid]);

// //     temp->left = solve(start,mid-1, ans);
// //     temp->right = solve(mid+1,end, ans);

// //     return temp;
// // }


// vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
// {
//     vector<int> v1;
//     vector<int> v2;

//     inorder(root1,v1);
//     inorder(root2,v2);

//     vector<int> ans;

//     int i=0;
//     int j=0;

//     // if(v1.size() == 0){
//     //     return v2;
//     // }
//     // if(v2.size() == 0){
//     //     return v1;
//     // }


//     while(i<v1.size() && j<v2.size()){
//         if(v1[i] <= v2[j]){
//             ans.push_back(v1[i]);
//             i++;
//         }
//         if(v1[i]>v2[j]){
//             ans.push_back(v2[j]);
//             j++;
//         }
//     }

//     while(i<v1.size()){
//         ans.push_back(v1[i]);
//         i++;
//     }
//     while(j<v2.size()){
//         ans.push_back(v2[j]);
//         j++;
//     }

//     return ans;


// }



// // // // Approach 2 // // // //



int main(){
    
}