#include<bits\stdc++.h>
using namespace std;
void valu(int *a){
    cout<<a<<endl;
}
void update(int *a){
    *a+=1;
    a+=1;
    
}
void bhallu(int *arr,int n){
    cout<<sizeof(arr)<<endl;
}
int main(){
    /*
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<"Printing the arr "<<arr<<endl;
    cout<<"Printing arr[0] "<<arr[0]<<endl;
    cout<<"Printing *arr "<<*arr<<endl;
    (*arr)++;
    cout<<arr[0]<<endl;
    cout<<*(arr+1)<<endl;
    

    int temp[10]={0};
    cout<<sizeof(temp)<<endl;

    int *ptr=&temp[0];
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;
    
    
    int a[20]={1,2,3,5};
    cout<<&a[0]<<endl;
    cout<<&a<<endl;
    cout<<a<<endl;

    int *p=&a[0];
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl;
    

    int arr[10];
//  arr+=1;                   This will give us an error because here we are trying to modify the symbol table
    int *ptr=&arr[0];
    cout<<ptr<<endl;
    ptr+=1;
    cout<<ptr<<endl;

    */

/*

    char ch[6]="abcde";
    int arr[5]={1,2,3,4,5};

    cout<<arr<<endl;
    cout<<ch<<endl;

    char *c=&ch[0];
    cout<<c<<endl;

    char temp='c';
    char *ca=&temp;
    cout<<ca<<endl;

    char *cha="abcde";
    cout<<cha<<endl;         // Chal to rha hai but very risky....
*/



/*    
    int temp=5;
    int *a=&temp;
    valu(a);
    cout<<a<<endl;
    update(a);
    cout<<a<<endl;
    cout<<*a<<endl;
*/

    int arr[5]={1,2,3,4,5};
    cout<<sizeof(arr)<<endl;
    bhallu(arr,5);           // It should give 8 at output though it is giving 4 but not 20 because it is passed as a pointer not as an array
    
}