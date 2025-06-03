#include<iostream>
using namespace std;
    int celebrity(vector<vector<int> >& M, int n) 
    { 
        // // Brute Force Approach // //
        
        // int zeroR=-1;
        // for(int i=0;i<n;i++){
        //     bool zeroRow=true;
        //     for(int j=0;j<n;j++){
        //         if(M[i][j]==1){
        //             zeroRow=false;
        //             break;
        //         }
        //     }
        //     if(zeroRow){
        //         zeroR=i;
        //         break;
        //     }
        // }
        // // cout<<"The zero Row is "<<zeroR<<endl;
        // // int oneCol;
        // bool oneCol=true;
        // if(zeroR!=-1){
        //     int j=zeroR;
        //     for(int i=0;i<n;i++){
        //         if(i!=j){
        //             if(M[i][j]==0){
        //                 oneCol=false;
        //                 // cout<<"Maine"<<endl;
        //                 break;
        //             }
        //         }
        //     }
        //     if(oneCol){
        //         return zeroR;
        //     }
        //     else{
        //         return -1;
        //     }
        // }
        // else{
        //     return -1;
        // }
        
        // // Optimised Approach // //
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(M[a][b]==1){
                st.push(b);
            }
            else if(M[b][a]==1 ){
                st.push(a);
            }
        }
        if(st.size()==0){
            return -1;
        }
        else{
            int may=st.top();
            bool rowDone=true;
            bool colDone=true;
            for(int j=0;j<n;j++){
                if(M[may][j]==1){
                    rowDone=false;
                    break;
                }
            }
            for(int i=0;i<n;i++){
                if(i!=may){
                    if(M[i][may]==0){
                        colDone=false;
                        break;
                    }
                }
            }
            // cout<<"HI";
            return (rowDone && colDone)?may:-1;
        }
    }

int main(){
    
}