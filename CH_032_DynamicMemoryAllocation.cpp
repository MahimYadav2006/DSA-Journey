#include<iostream>
using namespace std;
int main(){

/*
    // int n;
    // cin>>n;
    int row;
    cin>>row;
    int col;
    cin>>col;
    // Creation of this varible size 2d array
    int **arr=new int* [row];
    for(int i=0;i<row;i++){
        arr[i]=new int [col];
    }

    // Taking input
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    
    // Printing the 2d array
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Deleting the memory
    for(int i=0;i<row;i++){
        delete[] arr[i];
    }
    delete[] arr;

*/

    // Creation of jagged 2d array in static way using array of pointers
    // int row1[]={1,2,3};
    // int row2[]={1,2,3,4};
    // int row3[]={1,2};
    // int size[]={3,4,2};
    // int* arr[]={row1,row2,row3};
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<size[i];j++){
    //         cout<<*(arr[i]+j)<<" ";
    //     }
    //     cout<<endl;
    // }



    // // Dynamic creation of 2d arrays
    // int row;
    // cin>>row;
    // int* col=new int [row];
    // for(int i=0;i<row;i++){
    //     cin>>col[i];
    // }
    // int **arr=new int* [row];
    // for(int i=0;i<row;i++){
    //     arr[i]=new int[col[i]];
    // }

    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col[i];j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col[i];j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int *p=NULL;
    cout<<p<<endl;

}
